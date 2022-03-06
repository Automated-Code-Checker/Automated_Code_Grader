#include <stdio.h>

void update(int *a, int*b)
{
	/* update a to contain the sum of a and b */
	/* update b to contain the absolute diff of a and b */
	int v1, v2;
	int sumval;
	int absdiff;

	v1 = *a;
	v2 = *b;

	sumval = v1 + v2;

	if ((v1 > v2) || (v1 == v2))
	{
		absdiff = v1 - v2;
	}
	else
	{
		absdiff = v2 - v1;
	}

	/* update the value */
	*a = sumval;
	*b = absdiff;
}

int main(void)
{
	int a, b;
	int *pa = &a;
	int *pb = &b;

	scanf("%d %d", &a, &b);
	update(pa, pb);
	printf("%d\n%d\n", a, b);
	return 0;
}
