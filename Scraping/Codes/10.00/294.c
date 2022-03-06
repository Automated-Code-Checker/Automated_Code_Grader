#include <stdio.h>

void update(int *a,int *b) {
    int *stemp,*dtemp;
    stemp=*a+*b;
    dtemp=*a-*b;
    *a=stemp;
    *b=abs(dtemp);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}