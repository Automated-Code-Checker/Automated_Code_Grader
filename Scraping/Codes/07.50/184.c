#include <stdio.h>
int main()
{
   int first, second, *p, *q, sum,c;
   scanf("%d%d", &first, &second);

   p = &first;
   q = &second;

   sum = *p + *q;
   c=(*p-*q)*-1;
 printf("%d\n", sum);
 printf("%d\n",c);

   return 0;
}
