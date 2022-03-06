#include <stdio.h>
int main() {
    int a, b,add,sub;
    int *pa, *pb;
    scanf("%d%d",&a,&b);
    pa=&a;
    pb=&b;
    add=*pa+*pb;
    sub=*pb-*pa;
    printf("%d\n%d ",add,sub);


}
