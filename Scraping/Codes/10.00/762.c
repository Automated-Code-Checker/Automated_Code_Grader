#include <stdio.h>

void update(int *a,int *b) {
    int c,d,e;
    c=*a;
    d=*b;
    *a=c+d;
    e=c-d;
    if (e<0)
        e=e*(-1);
    *b=e;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}