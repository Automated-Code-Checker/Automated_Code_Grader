#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    int a1 = (*a) + (*b);
    int b1 = (*a) - (*b);
    if (b1<0)
        b1 = -1*b1;
    *a = a1;
    *b = b1;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}