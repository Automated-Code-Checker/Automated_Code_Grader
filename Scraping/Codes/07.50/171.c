#include <stdio.h>

void update(int *a,int *b) {
    int tempa=*a;
    int tempb=*b;
    *a=tempa+tempb;
    *b=tempb-tempa;
        
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
