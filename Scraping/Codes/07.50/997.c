#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int temp;
    temp=*b-*a;
    *a=*a+*b;
    *b=temp;
    
    return 1;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
