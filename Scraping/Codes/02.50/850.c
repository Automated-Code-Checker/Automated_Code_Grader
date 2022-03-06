#include <stdio.h>

void update(int *a,int *b) {
    int c;
    c=*a+*b;
    *b=*a-*b;
    *a=c;  
}

int main() {
    unsigned int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

