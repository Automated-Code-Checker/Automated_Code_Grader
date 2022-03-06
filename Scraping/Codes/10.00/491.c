#include <stdio.h>

void update(int *a, int *b) {
    int tmpA = *a + *b;
    int tmpB = abs(*a - *b);
    *a = tmpA;
    *b = tmpB;
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}