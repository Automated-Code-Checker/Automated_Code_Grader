#include <stdio.h>



int main() {
    int a, b;
    int *pa, *pb,*pc,*pd;
    pa = &a;
    pb = &b;
    scanf("%d %d", &a, &b);
    *pc=a+b;
    *pd=b-a;
    printf("%d\n%d", *pc, *pd);
    

    return 0;
}
