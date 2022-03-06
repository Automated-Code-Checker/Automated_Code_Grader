#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a = 0, b = 0;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    printf("%d\n%d", a + b, b - a);

    return 0;
}
