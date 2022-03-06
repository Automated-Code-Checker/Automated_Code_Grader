#include <stdio.h>
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    int sum=0,diff=0;
    scanf("%d%d",pa,pb);
    sum=*pa + *pb;
    diff=*pb - *pa;
    printf("%d",sum);
    printf("\n");
    printf("%d",diff);
    return 0;
}    
