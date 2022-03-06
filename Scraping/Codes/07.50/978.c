#include <stdio.h>

void update(int *a,int *b) {
    int stock = *a;
    *a = *a + *b;
    *b = *b - stock;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
