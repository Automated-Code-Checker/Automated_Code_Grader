#include <stdio.h>

void update(int *pa,int *pb) {
    // Complete this function
    int a = *pa;
    int b = *pb;
    *pa = a + b;
    *pb = a - b;
    if (*pb < 0)
        *pb *= -1;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
