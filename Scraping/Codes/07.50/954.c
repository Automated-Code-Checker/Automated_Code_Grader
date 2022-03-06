#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a;
    int b;
    int *pa = &a;
    int *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a+b, b-a);

    return 0;
}
