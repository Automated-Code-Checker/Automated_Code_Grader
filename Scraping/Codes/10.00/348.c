#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int sum_two = (*a) + (*b);
    int abs_two;
    if ((*a) > (*b))
        abs_two = (*a) - (*b);
    else
        abs_two = (*b)-(*a);

    *a = sum_two;
    *b = abs_two;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}