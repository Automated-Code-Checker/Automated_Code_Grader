#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    a=a+b;
    b=b*2-a;
    printf("%d\n%d", a, b);

    return 0;
}
