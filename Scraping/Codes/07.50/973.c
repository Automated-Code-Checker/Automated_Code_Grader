#include <stdio.h>
int main()
{
    int a,b;
    int *p,*q;
    scanf("%d%d",&a,&b);
    p=&a;
    q=&b;
    printf("%d\n",*p+*q);
    printf("%d",*q-*p);
}
