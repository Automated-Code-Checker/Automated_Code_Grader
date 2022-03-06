#include <stdio.h>

void update(int *a,int *b) {
    int t=*a,t1=*b;
    *a=t+t1;
    *b=(t-t1);
    if(*b<0)
        *b=(-1)*(*b);
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}