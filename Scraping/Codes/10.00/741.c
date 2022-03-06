#include <stdio.h>
#include <math.h>
void update(int *a,int *b) {
    int a2,b2;
    a2=*a+*b;
    b2=abs(*a-*b);
    *a=a2;
    *b=b2;
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