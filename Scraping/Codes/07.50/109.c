#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,c; 
    int *pa = &a, *pb = &b;
    
    scanf("%d %d %d ", &a, &b, &c);
    update(pa, pb);
    a=a+b;
    c=a-b;
    b=b-c;

    printf("%d\n%d", a, b);
    
    return 0;
}
