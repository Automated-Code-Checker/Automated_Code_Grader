#include <stdio.h>

void update(int *pa,int *pb) {
   *pa=*pa+*pb;
    *pb=*pa-*pb-*pb;
    *pb=abs(*pb);
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}