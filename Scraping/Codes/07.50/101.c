#include <stdio.h>

void update(int *a,int *b,int *sum,int *sub) {
   *sum=(*a)+(*b);
   *sub=(*b)-(*a);
}

int main() {
    int a, b ,sum,sub;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb,&sum,&sub);
    printf("%d\n%d", sum,sub);

    return 0;
}
