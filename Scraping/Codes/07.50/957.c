#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,x;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
x=a;
    a= *pa+*pb;
    
    b=*pb-x;
    printf("%d\n%d", a, b);

    return 0;
}
