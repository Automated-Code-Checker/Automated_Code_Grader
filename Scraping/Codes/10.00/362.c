#include <stdio.h>
#include <math.h>
#include<stdlib.h>
void update(int *a,int *b)
{
    int p,q,r,s;
    //printf("%d %d"a,*b);
    p=*a+*b;
   // printf("%d", p);
    q=abs(*a-*b);
    *a=p;
    *b=q;
   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}