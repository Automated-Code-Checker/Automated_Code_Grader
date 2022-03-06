#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,sum,diff;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    
    sum= a+b;
    diff= b-a;
    
    printf("%d\n%d", sum, diff);

    return 0;
}
