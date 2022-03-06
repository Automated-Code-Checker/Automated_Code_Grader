#include <stdio.h>

void update(int *a,int *b)
{
    int temp=*a;
    *a=*a+*b;
    if(*a>temp)
        *b=*a-temp;
    else 
        *b=temp-*a;
}


int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

