#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum, abs_dif;
    sum = *a + *b;
    abs_dif = *a - *b;
    if (abs_dif<0)
        abs_dif = abs_dif*(-1);
    
    *a = sum;
    *b = abs_dif;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}