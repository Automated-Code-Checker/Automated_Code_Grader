#include <stdio.h>
#include<stdlib.h>

void update(int *a,int *b) {
    
    // Complete this function    
}

int main() {
    int a, b,sum=0,sub=0;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    sum=a+b;
    sub=b-a;
    update(pa, pb);
    printf("%d\n%d",sum, sub);

    return 0;
}
