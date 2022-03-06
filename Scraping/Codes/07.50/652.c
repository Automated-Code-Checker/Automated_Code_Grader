#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,t;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    t=a;
    update(pa, pb);
    
    a=a+b;
    b=b-t;
    printf("%d\n%d", a, b);

    return 0;
}
