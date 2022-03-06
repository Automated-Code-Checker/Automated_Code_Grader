#include <stdio.h>

void update(int *a,int *b) {
    int aa,bb;
    aa=(*a)+(*b);
    bb=(*a)-(*b);
    if(bb<0)
    {
        bb=-1*bb;
    }
    *a=aa;
    *b=bb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}