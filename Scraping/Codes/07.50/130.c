#include <stdio.h>

void update(int a,int b) {
    int c,d;
    c=a+b;
    d=b-a;  
    printf("%d\n%d", c, d);
}

int main() {
    int a, b,*ptr,*ptr1;
    *ptr = &a;
    *ptr1 = &b;
    scanf("%d %d", &a, &b);
    update(a, b);
    return 0;
}
