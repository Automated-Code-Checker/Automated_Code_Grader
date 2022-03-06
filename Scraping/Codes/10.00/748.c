#include <stdio.h>

void update(int *a,int *b) {
    int p= (*a+*b);
    if((*a)-(*b)>0) *b=(*a-*b);
    else *b=(*b-*a);
    *a=p;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}