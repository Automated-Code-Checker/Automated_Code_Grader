#include<stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int e=0,f=0;
    e=a+b;
    f=abs(a-b);
    printf("%d\n%d",e,f);
    return 0;
}