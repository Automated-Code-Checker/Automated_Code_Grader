#include <stdio.h>


int main() {
    int a, b , sum , sub;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
   sum=a+b;
   sub=b-a;
    printf("%d\n%d", sum, sub);

    return 0;
}
