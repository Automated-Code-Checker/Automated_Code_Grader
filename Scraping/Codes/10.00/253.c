#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
   int c =*a+*b;
   int d =*a-*b;
    if (d<0)
        d=0-d;
    *a=c, *b=d;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}