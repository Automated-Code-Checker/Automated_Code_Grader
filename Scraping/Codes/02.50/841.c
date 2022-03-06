#include <stdio.h>

void update(int *a,int *b) {
    *a = *a + *b;
    if(*a>*b)
    {
        *a = *a - *b;
        
    }
    else if(*a<*b)
    {
        *a = *a - *b;
        *a = -*a;
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