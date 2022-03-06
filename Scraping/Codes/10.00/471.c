#include <stdio.h>

#define abs(x) ((x < 0)? -x : x)

void update(int *a,int *b) {
    int c = *a;
    *a = c + *b;
    *b = c - *b;
    *b = abs(*b);
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}