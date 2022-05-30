#include<stdio.h>
#include<string.h>

int main(){
	char str[30];
	int i=0,c=0;
	int j;
	printf("Enter your string:");
	gets(str);
	for( i=0;i<strlen(str);i++){
		for(j=2;j<i;j++)	{
			if(i%j==0)
			c=1;
		}
		if(c==1)
		{
			c=0;
			continue;
		}
		else if(i%10==3)
		str[i]='$';
		else
		;
	}
	for(int i=0;i<strlen(str);i++){
		printf("%c",str[i]);
	}
}
