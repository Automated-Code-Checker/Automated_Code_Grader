#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int tmpA;
    int tmpB;
    int x;
    int xMask;
    
    tmpA = *a;
    tmpB = *b;
    x = tmpA - tmpB;
    xMask = x >> 31;
    
    *a = tmpA + tmpB;
    *b = (x ^ xMask) - xMask;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}