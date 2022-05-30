#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    // Complete this function
    int temp1;
    int temp2;
    temp1= *a + *b;
    temp2= abs(*a - *b);
    *a = temp1;
    *b = temp2;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}