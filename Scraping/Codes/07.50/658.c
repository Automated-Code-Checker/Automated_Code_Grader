#include <stdio.h>

void update(int *a,int *b)
{
int c,d;
c=*a+ *b;
d= *a- *b;
return c,d;

}

int main() {
    int a, b;
    int c,d;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n",a+b);
    printf("%d",b-a);
    return 0;

}
