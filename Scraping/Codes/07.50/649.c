#include <stdio.h>

void update(int *a,int *b) {
  unsigned int sum , temp ,sub;
    sum= (*a+*b);
    sub=(*a-*b);     
    *a=sum;
    temp=(-sub);
    *b=temp;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
