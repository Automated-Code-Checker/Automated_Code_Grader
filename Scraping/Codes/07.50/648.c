#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b, c, d;
    int *pa = &a, *pb = &b, *pc=&c, *pd=&d;
    scanf("%d %d", &a, &b);
    c=a+b;
    d=b-a;
    printf("%d\n%d",*pc,*pd);
    

    return 0;
}
