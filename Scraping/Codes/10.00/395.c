#include <stdio.h>

void update(int *a,int *b) {
    int sum = 0;
    int dif = 0;
    sum = *a + *b;
    if(*b > *a)
        dif = *b - *a;
    else
        dif = *a - *b;
    *a = sum;
    *b = dif;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}