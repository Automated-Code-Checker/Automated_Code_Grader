#include <stdio.h>
#include<stdlib.h>
void update(int *a,int *b) {
    
    int s,d;
    s=*a+(*b);
    d=abs((*b)-(*a));
    *a=s;
    *b=d;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}