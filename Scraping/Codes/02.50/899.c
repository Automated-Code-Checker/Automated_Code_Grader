#include <stdio.h>

void update(int *a, int *b) {
    // NOTE: a = 4, b = 5
    *a = *b + *a;
    *b -= *a - *b;
    *b = -*b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

