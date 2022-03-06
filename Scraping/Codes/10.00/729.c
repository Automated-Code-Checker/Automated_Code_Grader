#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int ad,s;
    ad = *a+*b;
    s = abs(*a-*b);
    
    *a = ad;
    *b = s;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}