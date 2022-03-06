#include <stdio.h>

void update(int *a,int *b) {
    int a_cpy = *a;
    int b_cpy = *b;
    *a = a_cpy + b_cpy;
    *b = a_cpy - b_cpy;
    if (*b < 0) {
        *b *= -1;
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