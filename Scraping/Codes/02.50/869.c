#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum,diff;
    sum=*a+*b;
    diff=*a-*b;    
    printf("%d\n%d",sum,diff);}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}
