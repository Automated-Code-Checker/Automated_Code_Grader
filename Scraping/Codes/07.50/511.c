#include<stdio.h>
void pointersInC(int,int);
void pointersInC(int a,int b)
{
    int c=(a+b);
    int d=(b-a);
    printf("%d\n",c);
    printf("%d",d);
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    pointersInC(a,b);
    return 0;
}
