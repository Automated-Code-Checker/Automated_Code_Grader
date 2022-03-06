#include <stdio.h>

void update(int *a,int *b) {
   int a1,b1;
a1 = *a + *b;
//printf("%d\n",a1);
    b1 = *a - *b;
    //printf("%d\n",b1);
if(b1 < 0)
    b1 = -1*b1;
*a = a1;
*b = b1;
  
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}