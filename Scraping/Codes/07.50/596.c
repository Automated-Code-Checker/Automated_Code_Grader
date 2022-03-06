#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int sum = *a + *b;
    int diff = *b-*a;
   printf("%d\n%d", sum, diff);
      
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
 

    return 0;
}
