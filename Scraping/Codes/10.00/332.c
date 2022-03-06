#include <stdio.h>

void update(int *pa,int *pb) {
    *pa = *pa + *pb;
    *pb = *pa - *pb - *pb;
    if (*pb<0)
        *pb = -(*pb);
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}