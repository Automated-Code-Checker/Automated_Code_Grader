#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int a1,b1;
    a1=*a;
    a1=a1+(*b);
    b1=*b;
    b1=b1-*a;
    printf("%d\n",a1);
    printf("%u\n",b1);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);


    return 0;
}
