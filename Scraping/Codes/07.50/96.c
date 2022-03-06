#include <stdio.h>
int main()
{
   int first, second, *p, *q, add,sub;
   scanf("%d%d", &first, &second);

   p = &first;
   q = &second;

   add = *p + *q;
    printf("%d\n", add);
    
   sub=  *q-*p;
   printf("%d",sub);

  

   return 0;
}
