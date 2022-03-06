#include <stdio.h>

void update(int *a,int *b) {
   printf("%d\n",*a+*b);
    printf("%d",abs(*a-*b));// Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    

    return 0;
}