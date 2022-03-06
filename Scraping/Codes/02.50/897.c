#include <stdio.h>

void update(int *a,int *b) {
  int c ;
  c =*a + *b;
  int d;
  d=*a - *b;
  printf("%d\n%d",c,d);
   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    

    return 0;
}
