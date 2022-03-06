#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    int test = (*a);
    (*a) += (*b);
    (*b) = fabs(test - (*b));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}