#include <stdio.h>
#include <math.h>
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    printf("%d\n%d", *pa+*pb,abs(*pa-*pb));

    return 0;
}