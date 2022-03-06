#include<stdio.h>
void sum(int*,int*);
int main() 
{
    int a=4,b=5;
    scanf("%d %d ",&a,&b);
    sum(&a,&b);
    return 0;
}
void sum(int*a,int*b)
{
    int sum,sub;
    sum=*a+*b;
    printf("%d\n",sum);
    sub=*b-*a;
        printf("%d",sub);
    
}
