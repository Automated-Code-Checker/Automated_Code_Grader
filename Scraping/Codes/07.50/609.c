#include <stdio.h>

int main() {
    int a, b;
    int sum=0, sub=0;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    
    sum = a+b;
    sub = b-a;
    
    printf("%d\n%d", sum, sub);

    return 0;
}
