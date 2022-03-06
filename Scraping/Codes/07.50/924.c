#include <stdio.h>
#include<math.h>
void update(int *a,int *b) {
    int a1,b1;
   *a=*a+*b;
   if (*a<*b)
    *b=(*a-(*b)*2);
   else
   *b=2*(*b)-*a;
}
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
