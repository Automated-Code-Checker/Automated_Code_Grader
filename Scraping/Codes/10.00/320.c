#include <stdio.h>

void update(int *a,int *b) {
    int m,n;
    m = *a + *b;
    n = (*a>*b)?(*a - *b):(*b-*a);
    *a =m;
    *b =n;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}