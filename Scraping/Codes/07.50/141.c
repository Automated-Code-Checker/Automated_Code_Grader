#include <stdio.h>

void update(int *a,int *b);    
int main()
{
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    return 0;
}

void update(int* a,int* b)
{
    printf("%d\n%d",(*(a)+*(b)),-(*(a)-*(b)));
}
