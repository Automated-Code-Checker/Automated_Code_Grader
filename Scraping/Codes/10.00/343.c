#include <stdio.h>

void update(int *a,int *b) {
    int sm,abd;
    sm = *a+*b;
    abd = *a>*b?*a-*b:*b-*a;
    *a = sm;
    *b = abd;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}