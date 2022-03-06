#include <stdio.h>

void update(int *a,int *b) {
    int n,m;
n=*a+*b;
m=*b-*a;
printf("%d\n%d", n, m);


    
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    
    return 0;
}
