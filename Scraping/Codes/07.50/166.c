#include<stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int *pa = &a, *pb = &b;
    a=*pa+*pb;
    b=*pa-*pb-*pb;
    printf("%d\n%d",a,-b);
    return 0;
}
