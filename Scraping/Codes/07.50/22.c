#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b ,c ,d;
    int *pa = &a, *pb = &b;
    
    scanf("%d\n %d\n", &a, &b);
    c=a+b,d=b-a;
    printf("%d\n%d", c, d);

    return 0;
}