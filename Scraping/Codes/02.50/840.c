#include<stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d\n%d",&a,&b);
    int *p;
    int *p1;
    p=&a;
    p1=&b;
    c= *p + *p1;
    d=*p - *p1;
    printf("%d\n%d",c,d);
    
    
}