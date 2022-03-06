#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    int z=(*a)+(*b);
    int w=(*b)-(*a);
    *a=z;
    *b=w;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
