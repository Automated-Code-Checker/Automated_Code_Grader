#include <stdio.h>

void update(int *a,int *b) { 
    *a=*a+*b ;
    *b=*a-2*(*b) ;
    if(*b<0)
        *b=-*b;
}

int main() {
    int a, b;
    int *pa ,*pb;
    pa=&a;
    pb=&b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}