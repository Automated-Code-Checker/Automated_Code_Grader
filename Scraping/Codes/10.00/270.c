#include <stdio.h>
#include <math.h>
void update(int *a,int *b) {
    int *t1;
    t1=a;
    *a=*a+*b;
    *b=abs(*t1-2*(*b));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}