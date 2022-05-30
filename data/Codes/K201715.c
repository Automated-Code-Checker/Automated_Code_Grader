#include<stdio.h>
#include<conio.h>
int main()
{
	char val[50];
	int e,j,x,p=0;
	scanf("%[^\n]s",val);
	printf("%s",val);
	x=strlen(val);
	printf("%d",x);
	for(e=3;e<x;e++)
	{
		p=0;
		for(j=1;j<x;j++)
		{
			if(j<=e)
			{
				if(e%j==0)
				{
					p++;
				}
			}
		}
		if(p<=2)
		{
			if(e%10==3)
			{
				val[e]='$';
				
			}
		}
	}
	printf("%s\n",val);
}
