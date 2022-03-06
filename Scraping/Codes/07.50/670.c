#include <stdio.h>

void update(int *a,int *b) {
    int *c;
    *a = *a + *b;
   // printf("%d\n",*a);
    *b = *a - 2**b;
    *b = *b -2**b;
    
   // printf("%d\n",*b);
      
    
    
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
