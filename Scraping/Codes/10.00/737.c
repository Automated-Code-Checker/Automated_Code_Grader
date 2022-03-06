#include <stdio.h>

void update(int *a,int *b) {
    int x,y;
    y= *a + *b;
    x=*a-*b;
    if (x<0)
        x= -1*x;
    *a=y;
    *b=x;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}