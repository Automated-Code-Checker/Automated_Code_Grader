#include <stdio.h>
#define abs(a) (a<0?(a*(-1)):a)

void update(int *a,int *b) 
{ 
    int sum=*a + *b;
    *b = *a - *b;
    *a=sum;     
    return *a;
    return *b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, abs(b));

    return 0;
}