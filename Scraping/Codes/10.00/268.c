#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    // Complete this function  
    double * a_1;
    double * b_1;
    *a_1 = *a + *b ;
    *b_1 = abs(*b - *a);
    *a = *a_1;
    *b = *b_1;
 }

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}