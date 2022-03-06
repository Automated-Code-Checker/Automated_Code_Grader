#include <stdio.h>

void update(int *a,int *b) {
    int res_a = *a + *b;
    int res_b = *a - *b;

    *a = res_a;
    *b = res_b < 0 ? -res_b : res_b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
