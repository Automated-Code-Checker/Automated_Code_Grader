#include <stdio.h>

void update(int *a,int *b) 
{
    int sum,sub;
    sum= *a + *b;
    sub= *a ^ *b;
    printf("%d\n%d",sum,sub);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);

    return 0;
}
