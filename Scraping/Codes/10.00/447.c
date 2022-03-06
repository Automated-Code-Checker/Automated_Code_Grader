#include <stdio.h>

void update(int *a,int *b) {
    int store1 = *a;
    int store2 = *b;
    *a = store1 + store2;
    *b = abs(store1 - store2);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}