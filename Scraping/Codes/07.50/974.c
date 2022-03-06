#include <stdio.h>

void update(int *a,int *b,int*c, unsigned int*d){
  *c=(*a)+(*b);
   *d =(*b)-(*a);
}

int main() {
    int a, b,c,d;
    int *pa = &a, *pb = &b, *pc = &c,*pd = &d;
    
    scanf("%d\n %d", &a, &b);
    
    update(pa, pb,pc,pd);
    printf("%d\n%d",c,d);

    return 0;
}
