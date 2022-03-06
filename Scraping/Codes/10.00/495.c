#include <stdio.h>

void update(int *a,int *b) {
    int c=*a;
    int d=*b;
    *a=c+d;
    int e=c-d;
    if(e<0)
        *b=-1*e;
    else
        *b=e;
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}