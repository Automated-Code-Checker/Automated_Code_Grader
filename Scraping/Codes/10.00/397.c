#include <stdio.h>

void update(int *a,int *b) {

    if(*a>*b)
    {
        *b=*a-*b;
        *a=*a+*a-*b;
    }
    else
    {
        *b=*b-*a;
        *a=*a+*a+*b;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
