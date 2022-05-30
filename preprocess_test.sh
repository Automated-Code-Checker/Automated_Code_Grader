#!/usr/bin/env bash
# C extractor for code2vec
#
# Copyright 2019 Carnegie Mellon University. All Rights Reserved.
#
# NO WARRANTY. THIS CARNEGIE MELLON UNIVERSITY AND SOFTWARE ENGINEERING INSTITUTE MATERIAL IS FURNISHED ON AN "AS-IS" BASIS. CARNEGIE MELLON UNIVERSITY MAKES NO WARRANTIES OF ANY KIND, EITHER EXPRESSED OR IMPLIED, AS TO ANY MATTER INCLUDING, BUT NOT LIMITED TO, WARRANTY OF FITNESS FOR PURPOSE OR MERCHANTABILITY, EXCLUSIVITY, OR RESULTS OBTAINED FROM USE OF THE MATERIAL. CARNEGIE MELLON UNIVERSITY DOES NOT MAKE ANY WARRANTY OF ANY KIND WITH RESPECT TO FREEDOM FROM PATENT, TRADEMARK, OR COPYRIGHT INFRINGEMENT.
# Released under a MIT (SEI)-style license, please see license.txt or contact permission@sei.cmu.edu for full terms.
# [DISTRIBUTION STATEMENT A] This material has been approved for public release and unlimited distribution.  Please see Copyright notice for non-US Government use and distribution.
# Carnegie Mellon® and CERT® are registered in the U.S. Patent and Trademark Office by Carnegie Mellon University.
# This Software includes and/or makes use of the following Third-Party Software subject to its own license:
# 1. code2vec (https://github.com/tech-srl/code2vec/blob/master/LICENSE) Copyright 2018 Technion.
# 2. LLVM / CLANG (https://github.com/llvm-mirror/clang/blob/master/LICENSE.TXT) Copyright 2019 LLVM.
# DM19-0540

# Configuration is relative to this script
realpath() {
    [[ $1 = /* ]] && echo "$1" || echo "$PWD/${1#./}"
}
SCRIPT_LOC=$(realpath "$0")
SCRIPT_PATH="$(dirname "$SCRIPT_LOC")"
# . $SCRIPT_PATH/configure.sh

CLANG_PATH=/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/lib/libclang.dylib
# CODE2VEC_LOC - should be the location of base codevec
CODE2VEC_LOC=/Users/unaissiddiqui/Desktop/Fyp/Automated_Code_Grader
# SOURCE_DIR - top level folder for C source files
SOURCE_DIR=$2

### Give or use less resources
# MEM_PERCENT - for configurable commands like sort limit increase memory percentage to use
MEM_PERCENT=75
# NUM_PROCESSORS - for configurable commands like sort raise the number of processors to use
NUM_PROCESSORS=2 
# MAX_LEAVES - maximum number of leaves in an AST for parsing 
#    (default 32, remeber function complexity is ~ leaves^2)
MAX_LEAVES=3000
# DOWNSAMPLE - Reduce the size of the dataset.  Change to a percentage (ex. DOWNSAMPLE=.8)
# to only use a portion of the available features.
DOWNSAMPLE=1
# SKIP_DECLS - Comment out this line to tag function decls instead of skipping them.
# SKIP_DECLS=--skip-decls true

# code2vec parameters
# DATASET_NAME is just a name for the currently extracted dataset.                                              
# MAX_CONTEXTS is the number of contexts to keep for each 
#   method (by default 200).                              
# WORD_VOCAB_SIZE, PATH_VOCAB_SIZE, TARGET_VOCAB_SIZE -   
#   - the number of words, paths and target words to keep 
#   in the vocabulary (the top occurring words and paths will be kept). 
#   The default values are reasonable for a Tesla K80 GPU 
#   and newer (12 GB of board memory).

DATASET_NAME=$3
MAX_CONTEXTS=200
WORD_VOCAB_SIZE=1301136
PATH_VOCAB_SIZE=911417
TARGET_VOCAB_SIZE=261245
NUM_THREADS=64
PYTHON=python3



[ ! -d ${CODE2VEC_LOC} ] && echo "code2vec location does not exist!" && exit 1
[ ! -d ${SOURCE_DIR} ] && echo "source directory does not exist!" && exit 1

DATA_ROOT=${CODE2VEC_LOC}/data/${DATASET_NAME}
RAW_DATA_FILE=${DATA_ROOT}/${DATASET_NAME}.raw.txt
SORTED_DATA_FILE=${DATA_ROOT}/${DATASET_NAME}.sorted.raw.txt
DATA_FILE=${DATA_ROOT}/${DATASET_NAME}.data.raw.txt

# Ensure previous runs are cleared out...
rm -rf $DATA_ROOT
mkdir -p $DATA_ROOT

echo "Extracting paths from data set..."
${PYTHON} ${SCRIPT_PATH}/extract-c.py --dir ${SOURCE_DIR} -outdir ${DATA_ROOT} ${SKIP_DECLS} -maxleaves ${MAX_LEAVES} --train-flag $1 --num_threads ${NUM_THREADS} --clang-path ${CLANG_PATH} --include-path ${SOURCE_DIR} > ${RAW_DATA_FILE} 2>> ${DATA_ROOT}/stderr.txt
echo "Finished extracting paths from data set"
sort -u -R -S ${MEM_PERCENT}% --parallel ${NUM_PROCESSORS} --output=${SORTED_DATA_FILE} ${RAW_DATA_FILE}

echo "Calculating lines"
n=$(wc -l < ${SORTED_DATA_FILE})
[[ ! "$n" -gt "0" ]] && echo "Extracted no lines. (missing source files?)" && exit 1

n=$(echo "x=${n} * ${DOWNSAMPLE}; scale = 0; x / 1" | bc -l)


echo "N: $n"
# n=63
# echo "N: $n"
echo "Extracting samples to raw files."
cat ${SORTED_DATA_FILE} | { head -n ${n} > ${DATA_FILE};}
echo "Done extracting samples to raw files."

TARGET_HISTOGRAM_FILE=${DATA_ROOT}/${DATASET_NAME}.histo.tgt.c2v
ORIGIN_HISTOGRAM_FILE=${DATA_ROOT}/${DATASET_NAME}.histo.ori.c2v
PATH_HISTOGRAM_FILE=${DATA_ROOT}/${DATASET_NAME}.histo.path.c2v

echo "Creating histograms from the training data"
cat ${DATA_FILE} |  tee \
>(cut -d' ' -f1 | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > ${TARGET_HISTOGRAM_FILE}) \
| cut -d' ' -f2- | tr ' ' '\n' | tee \
>(cut -d',' -f1,3 | tr ',' '\n' | awk '{n[$0]++} END {for (i in n) print i,n[i]}' > ${ORIGIN_HISTOGRAM_FILE}) \
| cut -d',' -f2 | sort -S ${MEM_PERCENT}% --parallel ${NUM_PROCESSORS} | uniq -c | awk '{ t = $1; $1 = $2; $2 = t; print; }' > ${PATH_HISTOGRAM_FILE}
echo "Done creating histograms...sending to code2vec for preprocessing"

${PYTHON} ${CODE2VEC_LOC}/preprocess_test.py --data ${DATA_FILE} \
  --max_contexts ${MAX_CONTEXTS} --word_vocab_size ${WORD_VOCAB_SIZE} --path_vocab_size ${PATH_VOCAB_SIZE} \
  --target_vocab_size ${TARGET_VOCAB_SIZE} --word_histogram ${ORIGIN_HISTOGRAM_FILE} \
  --path_histogram ${PATH_HISTOGRAM_FILE} --target_histogram ${TARGET_HISTOGRAM_FILE} --output_name ${DATA_ROOT}/${DATASET_NAME}
    
# This line can be uncommented if disk usage is of primary concern.  This will delete intermediary files which are 
# redundant and sizeable.
rm ${DATA_FILE} ${TARGET_HISTOGRAM_FILE} ${ORIGIN_HISTOGRAM_FILE} \
 ${PATH_HISTOGRAM_FILE} ${RAW_DATA_FILE} ${SORTED_DATA_FILE}