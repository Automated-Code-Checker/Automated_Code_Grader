#include<stdio.h>
#include<string.h>
int main(){
	
	char sen[50];
	int num, i;
	
	printf("Enter a sentence: ");
	gets(sen);
	
	num=strlen(sen);
	
	for(i=3; i<num; i++){
		if (num%i==0){
			continue;
		}
		else{
		if(i%10==3){
				sen[i]='$';
			}
		}
	}
	
	for(i=0; i<num;i++){
		printf("%c",sen[i]);
	}
	
}