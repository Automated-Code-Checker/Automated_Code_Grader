#include<stdio.h>

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    //update(pa, pb);
    printf("%d\n%d", b+a,b-a);
    return 0;
}
