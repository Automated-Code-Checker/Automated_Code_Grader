#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,c,d;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    c=*pa+*pb;
    d=*pb-*pa;
    
    printf("%d\n%d", c, d);

    return 0;
}
