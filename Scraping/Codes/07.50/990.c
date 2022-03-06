#include <stdio.h>

void update(int *a,int *b) {
    int max;
    int min;
    max=*b+*a;
    min=*b-*a;
    *a=max;
    *b=min;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
