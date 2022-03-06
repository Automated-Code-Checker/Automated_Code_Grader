#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a=4, b=5;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa=a+b, pb=-a+b);
    printf("%d\n%d", pa, pb);

    return 0;
}
