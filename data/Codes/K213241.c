#include<stdio.h>
#include<string.h>


int main(){
	
	char text[90];
	
	int i, flag = 1, num;
	
	gets(text);

	for(num = 3;i < strlen(text);num = num+10){
		flag = 1;
		for (i = 2;i < num/2;i++){
			if ( num % i == 0){
				flag = 0;
				break;
			}
		}
		if (flag == 1){
			text[num] = '$';
			flag = 0;
		}
		
		
	}
	
	printf("%s", text);
}
