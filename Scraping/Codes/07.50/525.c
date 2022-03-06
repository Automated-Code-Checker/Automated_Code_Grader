#include <stdio.h>

void update(int *pa,int *pb) {
    int sml;
     sml = *pa + *pb;
     *pb = *pb - *pa;
     *pa = sml;
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);
    return 0;
}
