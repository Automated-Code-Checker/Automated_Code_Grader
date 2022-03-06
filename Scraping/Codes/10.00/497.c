#include <stdio.h>

void update(int *a,int *b) {
    int aux=*a;
    *a=aux+*b;
    *b=abs(aux-*b);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}