#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b, c, d;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    c = a+b;
    d = b-a;
    printf("%d\n", c);
    printf("%d\n", d);
    return 0;
}                                                                            