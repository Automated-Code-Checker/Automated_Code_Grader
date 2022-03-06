#include <stdio.h>
#include <math.h>
#include <stdlib.h>

    // Complete this function    

void update(int *x,int *y);
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

void update(int *x,int *y)
{
    int *s,*p;
    *s=*x+*y;
    *p=abs(*x-*y);
    *x=*s;
    *y=*p;

}
