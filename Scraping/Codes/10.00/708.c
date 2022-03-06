#include <stdio.h>
#include <math.h>

void update(int *a,int *b) 
{
    int *tempA;
    int *tempB;
    // Complete this function
    *tempA = *a + *b;
    *tempB = fabs(*a - *b);
    *a = *tempA;
    *b = *tempB;    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}