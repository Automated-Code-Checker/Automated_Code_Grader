#include <stdio.h>

void update(int *a,int *b) {
    int *p1,*p2,*temp;
    p1 = a;
    p2 = b;
    *temp = *a;
    
    *a = *p1 + *p2;
    *b = *p2 - *temp;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
