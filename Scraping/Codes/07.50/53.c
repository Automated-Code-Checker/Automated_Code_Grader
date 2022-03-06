#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum=0,sub=0;
    sum = *a+*b;
    sub =*b-*a;
    //a=&sum;
    //b=&sub;    
    printf("%d\n%d",sum , sub);

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    
    return 0;
}
