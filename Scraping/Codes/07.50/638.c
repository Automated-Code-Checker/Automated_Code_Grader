#include<stdio.h>
int main()
{
    int a,b,*sum,*sub;
    scanf("%d%d",&a,&b);
    sum=a+b;
    printf("%d\n",sum);
    sub=-(a-b);
    printf("%d",sub);
}
