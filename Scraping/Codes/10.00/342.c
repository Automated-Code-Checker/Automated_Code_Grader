#include <stdio.h>

void update(int *a,int *b) {
    printf("%d\n", *a + *b);
    printf("%d\n", abs(*a - *b));
    return;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}