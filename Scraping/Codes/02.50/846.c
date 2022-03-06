#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    if (*a > *b) {
        *a = *a + *b;
        *b = *a - 2 * *b;
    } else {
        *a = *a + *b;
        *b = *b - 2 * *a;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}