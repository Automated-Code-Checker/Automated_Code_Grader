#include <stdio.h>

void update(int *,int *);
 

int main() {
    int a, b;
    int *pa,*pb;
    pa = &a, 
    pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
   // printf("%d\n%d", a, b);

    return 0;
}
void update(int *pa,int *pb)
{
  int a,b;  
    a=*pb+*pa;
    b=*pb-*pa;
     printf("%d\n%d", a, b);
}
