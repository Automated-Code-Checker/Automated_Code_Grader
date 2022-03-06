#include <stdio.h>

#define ABS(x) (((x) < 0) ? (-(x)) : (x))

void update(int *a,int *b) {
    int x = *a;
    int y = *b;
    
    *a = x + y;
    *b = ABS(x - y);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
