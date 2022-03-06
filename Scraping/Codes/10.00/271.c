#include <stdio.h>
#include <math.h>
void update(int *a,int *b) {
    // Complete this function  
    int m, n;
    m = *a+*b;
    n = abs(*a-*b);
    *a = m;
    *b = n;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}