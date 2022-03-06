#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void update(int *a,int *b) {
    int a1,a2;
    a1 = *a + *b;
    a2 = *a - *b;
        if(a2<0)
            a2 = -1*a2;
    *a=a1;
    *b=a2;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}