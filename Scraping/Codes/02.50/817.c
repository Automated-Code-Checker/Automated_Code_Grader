#include <stdio.h>
int main()
{
    int a=7,b=0,*m,*n,sum,sub;
    m = &a;
    n = &b;
    sum = *m + *n; 
    sub = *m - *n;
    printf("%d\n%d\n",sum,sub);
   return 0;
}