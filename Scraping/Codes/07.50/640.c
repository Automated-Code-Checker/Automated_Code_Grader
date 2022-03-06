#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int *c;
    *c = (*a)+(*b);
    *b = (*a>*b) ? (*a)+(*b) : (*b)-(*a);
    *a = *c;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}