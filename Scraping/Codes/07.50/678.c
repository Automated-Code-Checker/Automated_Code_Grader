#include <stdio.h>

void update(int *,int *);

int main() 
{
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a,&b);
    return 0;
}
void update(int *a, int *b)
{
    int A,B;
    A = *a + *b;
    B = -1*(*a - *b);
    printf("%d\n%d",A,B);
}
