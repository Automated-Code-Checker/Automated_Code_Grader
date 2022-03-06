#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;  
    scanf("%d %d", &a, &b);
    int *pa = &a, *pb = &b;
    printf("%d\n%d", *pa+*pb,*pb-*pa);

    return 0;
}
