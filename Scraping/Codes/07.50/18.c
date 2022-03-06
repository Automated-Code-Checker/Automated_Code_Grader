#include <stdio.h>

void update(int *a,int *b) {
    int p, q;
    // Complete this function    
    p = *a + *b;
    q = *b - *a;
    *a = p;
    *b = q; 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
