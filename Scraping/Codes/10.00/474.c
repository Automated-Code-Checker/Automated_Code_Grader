#include <stdio.h>

void update(int *a,int *b) {
    int ua = *a+*b;
    
    int ub = *a-*b > 0 ? *a-*b : *b-*a;
    *a = ua;
    *b = ub;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}