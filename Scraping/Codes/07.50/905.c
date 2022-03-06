#include <stdio.h>

void update(int *a,int *b) {
   int c,d;
   c=*a+*b; 
   d=*b-*a; 
   printf("%d\n",c);
    printf("%d\n",d);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    

    return 0;
}
