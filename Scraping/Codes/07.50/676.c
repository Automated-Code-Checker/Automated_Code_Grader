#include <stdio.h>

void update(int *a,unsigned int *b) {
    int temp=*a;
     *a=*a+*b;
    *b=*b-temp ;
   
     
}

int main() {
    int a;
    unsigned int b;
    int *pa = &a;
    unsigned int  *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
