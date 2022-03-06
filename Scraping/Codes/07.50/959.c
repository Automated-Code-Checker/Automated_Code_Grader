#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int x,y;
    x=*a+*b;
    y=*b-*a;
    printf("%d\n%d",x,y);    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    return 0;
}
