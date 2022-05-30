#include <stdio.h>

void update(int *a,int *b) 
{ 
    int x,m,n;
    x = *a + *b;
    m = *a - *b;
    *a = x;
    if(*a<*b)
    {
        *b = m;
    }    
    else 
    {
        *b = -m;
    } 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}