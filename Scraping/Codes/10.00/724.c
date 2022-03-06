#include <stdio.h>

void update(int *a,int *b) {
    int c,d;
    c= *a+*b;
    if ((*a-*b)<0)
        d=*b-*a;
    else
        d=*a-*b;
    *a=c;
    *b=d;
    return 0;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}