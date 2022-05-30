#include<stdio.h>
#include<string.h>
int main()
{
	char str[200];
	printf("Enter a sentence: ");
	fflush(stdin);
	gets(str);
	int i, L, j, num, count = 0;
	L = strlen(str);
	
	for(i=0; i<L; i++)
	{
		num = i;
		count = 0;
		for(j=2; j<L; j++)
		{
			if(num % j == 0 && num != j)
			{
				count++;
			}
//			printf("%d", count);
		}
		if(count == 0)
		{
			num = num % 10;
			if(num == 3)
			{
				str[i] = 36; 	
			}
		}
			printf("%c", str[i]);
	}
}