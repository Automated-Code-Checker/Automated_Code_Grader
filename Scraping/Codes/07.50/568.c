

#include <stdio.h>
void update(int *x,int *y)
{
    int c,d;
  c=*x+*y;
    d=*x-*y;
    printf("%d\n",c);
    printf("%d",(d*-1));
}
int main() {
    int a,b,c,d;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa,pb);
    return 0;
}

