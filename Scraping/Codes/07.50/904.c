#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    printf("%d\n",*a+*b);
    printf("%d",*b-*a);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    
    
    update(pa, pb);
    return 0;
}
