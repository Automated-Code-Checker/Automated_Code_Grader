#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int aO = *a;
    int bO = *b;
    *a = aO + bO;
    *b = abs(aO - bO); 
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}