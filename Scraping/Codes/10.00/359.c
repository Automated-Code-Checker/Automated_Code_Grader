#include <stdio.h>
#include<math.h>

void update(int *a,int *b) {
    int sum=*a+*b;
    int diff=fabs(*a-*b);
    *a=sum;
    *b=diff;
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