# Automated_Code_Grader


# Abstract

The ever-increasing demand for automated code assessment has prompted us to evaluate existing resources. Current methods include running the code through a set of test cases, grading on fixed criteria for generalized semantic structures, or calculating document similarities. Because these systems do not respond to the semantic understanding of the code, they fail to tolerate partially correct solutions. This project proposes using Code2Vec as a base, where meaningful code-vector-encodings are derived from the abstract syntax tree and trained on various approaches for evaluating student-written codes that replicate human checking. The efficacy of this approach on C-language codes is shown by predicting marks(grades) against the vector formed from the code file. It was important to train on a dataset containing diverse solution files, ranging from incorrect-partially correct- correct, hence we crowdsourced the data from students currently enrolled in a BS-CS program. The project discusses the performance of this approach on multiple Neural Network models, trained on the same dataset.
