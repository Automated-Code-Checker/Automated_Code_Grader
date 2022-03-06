#include <stdio.h>

void update(int *a,int *b) {
    int aux=*a-*b;
    *a=*a+*b;
    if (aux>0)
        *b=aux;
    else
        *b=-aux;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}