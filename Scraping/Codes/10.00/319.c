#include <stdio.h>

void update(int *a,int *b) {
    int va = *a;
    int vb = *b;
    *a = va + vb;
    *b = va > vb ? va - vb : vb - va;
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