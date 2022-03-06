#include <stdio.h>

void update(int *a,int *b) {
    int a_new=*a+*b;
    int b_new=*b-*a;
    *a=a_new;
    *b=b_new;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
