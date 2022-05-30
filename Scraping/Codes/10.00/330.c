#include <stdio.h>

void update(int *a,int *b) {
    int a2 = *a;
    *a += *b;
    *b -= a2;
    if(*b<0) *b-=(*b*2);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}