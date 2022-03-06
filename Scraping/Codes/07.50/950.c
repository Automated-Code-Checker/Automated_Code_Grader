#include <stdio.h>
void fuc(int*p,int*q);
int main() {
    int a, b;
    scanf("%d %d",&a,&b);
    fuc(&a,&b);
     
    return 0;
}
void fuc(int*p,int*q)
{
    int a,b;
    a=*p+*q;
    b=*q-*p;
    printf("%d\n%d",a,b);
    
}
