#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    signed int n1,n2;
    n1=*a+*b;
    n2=abs(*a-*b);
    *b=n2;
    *a=n1;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}