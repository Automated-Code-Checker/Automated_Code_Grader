#include<stdio.h>
#include<string.h>

int main(){
	int i,count=0;
	
	char str[]={"This is a string"};
	
	for(i=0;i<strlen(str);i++){
		if(count==3){
			str[i]='$';
		}
		count++;
		if(str[i]==' '){
			count=0;
		}
	}
	puts(str);
}
