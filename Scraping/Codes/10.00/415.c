#include <stdio.h>
#include<stdlib.h>

void update(int *a,int *b)
{
    int temp=*a;
    *a=*a+*b;
    *b=abs(temp-(*b));
    return;
}

int main ()
{
    int a,b;
    scanf("%d\n%d",&a,&b);
    update(&a,&b);
    printf("%d\n%d",a,b);
}