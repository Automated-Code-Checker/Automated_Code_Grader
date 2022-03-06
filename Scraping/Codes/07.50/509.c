#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int s,ad,adf;
    s=(*a)+(*b);
    ad=(*a)-(*b);
    adf=ad*(-1);
    *a=s;
    *b=adf;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
