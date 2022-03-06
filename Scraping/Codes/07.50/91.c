#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int A=*a+*b;
    int B=*a-*b;
    if(B<0){
    B=B*-1;
    *a=A;
    *b=B;
    } 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
