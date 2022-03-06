#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int add_ab=*a+*b;
    int sub_ab=*a-*b;
    sub_ab=-(sub_ab);
    *a=add_ab;
    *b=sub_ab;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
