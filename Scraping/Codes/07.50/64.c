#include <stdio.h>
int main()
{
   int fir, sec, *p, *q, sum,diff;

  
   scanf("%d%d", &fir, &sec);
   p = &fir;
   q = &sec;
   sum = *p + *q;
   diff= *q - * p;
   printf("%d\n%d\n",sum,diff);

   return 0;
}
