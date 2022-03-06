#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c,d;
    scanf("%d %d ",&a,&b);
    c=a+b;
    d=b-a;
    int *p=&c;
    int *ptr=&d;
    printf("%d\n",*p);
    printf("%d\n",*ptr);
}
