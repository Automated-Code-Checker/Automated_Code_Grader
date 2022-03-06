#include <stdio.h>

void update(int *a,int *b) {
    int u = *a;
    int f = *b;
    
    *a = u + f;
    *b = u - f;
    
    if(*b < 0) {
        *b = *b * -1;
    }
    
    return 0;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}