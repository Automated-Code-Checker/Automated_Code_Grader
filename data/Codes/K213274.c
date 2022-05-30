#include<stdio.h>
#include<string.h>

int main()
{
	char x[20]="This is a string";;
	printf("%s",x);
	x[3]="$";
	x[13]="$";
	printf("\n");
	printf("%s",x);
}