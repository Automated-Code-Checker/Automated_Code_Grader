#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int p =*a+*b;
    int q =abs(*a-*b);
    *a=p;
    *b=q;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}