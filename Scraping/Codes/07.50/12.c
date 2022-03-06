#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    int c=a+b;
    int d =a-b;
     d=-d;
    printf("%d\n%d", c, d);

    return 0;
}
