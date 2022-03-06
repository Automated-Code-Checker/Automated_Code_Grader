#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b, add, sub;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    add = a+b;
    sub = b-a;
    // update(pa, pb);
    // printf("%d\n%d", a, b);
    printf("%d\n%d",add, sub);

    return 0;
}
