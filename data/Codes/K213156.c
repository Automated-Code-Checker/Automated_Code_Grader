#include<stdio.h>
#include<string.h>
int main()
{
	int st, i=0;
	char sent[25];
	printf("Enter your sentence: ");
	gets(sent);
	for(int i=0;i<25;i++)
	{
		st= i%10;
		if(st==3)
		{
			sent[i]='$';
		}
		if(sent[i]==' '&& sent[i+1]!=' '&& sent[i+2]!=' '&&sent[i+3]!=' ')
		{
			sent[i+4]='$';
		}
	}
	printf("%s",sent);
	
}
