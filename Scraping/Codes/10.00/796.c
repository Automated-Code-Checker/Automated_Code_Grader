#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,o;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    if(*pa>*pb)
    o=*pa-*pb;
    else
        o=*pb-*pa;
    
    printf("%d\n%d", *pa+*pb,o);

    return 0;
}