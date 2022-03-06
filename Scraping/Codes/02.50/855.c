#include <stdio.h>

void update(int *a,int *b) 
{
    int x,y;
    x=*a;
    y=*b;
    printf("%d \n%d",x+y,x-y);

}

int main() 
{
    int a, b;
    
    scanf("%d %d", &a, &b);
    update(&a,&b);

    return 0;
}

