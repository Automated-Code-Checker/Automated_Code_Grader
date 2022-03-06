#include <stdio.h>

void update(int *a,int *b) {
   int temp2;
    int temp1=*a+*b;
    temp2=*b-*a; 
    *a=temp1;
    *b=temp2; 
};

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
