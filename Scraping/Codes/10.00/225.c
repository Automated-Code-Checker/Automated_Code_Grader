#include <stdio.h>
#include <math.h>

void update(int *a,int *b) 
{
    int c = *a + *b;
    int d = *a - *b;
    if (c<0)
    {
        c = c*(-1);
    }
    if (d<0)
    {
        d = d*(-1);
    }
    *a = c;
    *b = d;
}

int main() 
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}