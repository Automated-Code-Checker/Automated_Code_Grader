#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int i = *a;
    *a += *b;
    *b = abs(*b - i);
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}