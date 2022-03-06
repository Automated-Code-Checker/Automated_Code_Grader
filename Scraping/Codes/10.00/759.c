#include <stdio.h>

void update(int *a,int *b) 
{
    int summation;
    int difference;
    summation=*a+*b;
    difference=*a-*b;
    if(difference<0)
    {
        difference=-difference;
    }
    *a=summation;
    *b=difference;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}