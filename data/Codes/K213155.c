#include<stdio.h>
int main()
{
	char sent[20];
	sent[20]="this is a string";
	int i;
	for (i=3;i<20;i+13)
	{
		if (i%3==0)
		{
			sent[i]="$";
		}
	}
	printf(sent);
	return 0;
}
