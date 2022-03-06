#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int t,u;
    t=*a+*b;
    if(*a>*b)
        u=*a-*b;
    else
        u=*b-*a;
    *a=t;
    *b=u;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}