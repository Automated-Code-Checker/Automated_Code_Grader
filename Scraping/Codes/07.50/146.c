#include <stdio.h>

void update(int *a,int *b) {
    int A =  *a + *b;
    *b =  *a - *b;
    *a = A;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    // b > 0?b:b*(-1);
    printf("%d\n%d", a, b*-1);

    return 0;
}
