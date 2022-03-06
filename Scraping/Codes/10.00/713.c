#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    int x = *a + *b;
    int absDifference = *a - *b > 0 ? *a - *b : -(*a - *b);
    
    *a = x;
    *b = absDifference;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}