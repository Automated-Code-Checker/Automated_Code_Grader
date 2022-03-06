#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b ,sub,sum;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    
    sum=a+b;
    sub=b-a;
    printf("%d\n%d",sum,sub);
     return 0;
}
