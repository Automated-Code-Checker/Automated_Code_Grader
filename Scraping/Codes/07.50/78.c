#include <stdio.h>

void update(int *a,int *b) 
{
    // Complete this function    
    int p = *a;
    (*a)=(*a)+(*b);
    (*b)=(*b)-p;
}

int main() {
    int a, b;
    int *c = &a, *d = &b;
    
    scanf("%d %d", &a, &b);
    update(c, d);
    printf("%d\n%d", a, b);

    return 0;
}
