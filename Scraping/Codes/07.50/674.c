#include<stdio.h>
void update(int *x,int *y) 
{
    *x=(*x)+(*y);
    
    *y=*x-2*(*y);
    *y=-(*y);
   
}

int main() 
{
    int a,b;
    scanf("%d\n%d",&a,&b);
    update(&a,&b);
    printf("%d\n%d",a,b);
    return 0;
}
