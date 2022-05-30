//1 2 3 5 7 11
#include<stdio.h>
#include<string.h>

int main()
{
	char s[50];
	int i, j;
	printf("Enter the string:\n");
	gets(s);
	
	for(i=0; i<50; i++)
	{
		if(i==3 || i==13 || i==23 || i==33 || i==43 )
		{
			s[i] = '$';	
		}	
	}	
	

		printf("\nThe output is: %s", &s[50]);	
	
	

return 0;	

}
