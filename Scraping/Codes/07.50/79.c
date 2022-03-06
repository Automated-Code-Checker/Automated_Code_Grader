#include <stdio.h>

void update(int *a,int *b,int *sum,int *dif) {
    *sum = *a + *b;
    *dif = *b - *a;
        
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    int sum,dif;
    scanf("%d %d", &a, &b);
    update(pa, pb,&sum,&dif);
    printf("%d\n%d", sum, dif);

    return 0;
}
