#include <stdio.h>

void update(int *a,int *b) {
     printf("%d\n%d",*a+*b,*b-*a)   ;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
  
    return 0;
}
