#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void change(int *a , int *b);

int main(void)
{
	int a , b;
	
	scanf("%d %d",&a,&b);

	change(&a,&b);

	printf("%d\n%d\n" , a , b);
}

void change(int *a , int *b)
{
	int x = *a;
	int y = *b;
	*a = x + y ;

	*b = abs(x - y);
}