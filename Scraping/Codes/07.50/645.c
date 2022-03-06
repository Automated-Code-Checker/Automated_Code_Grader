#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,a_,b_;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    a_=a+b;
    b_=-(a-b);
    
    printf("%d\n%d", a_, b_);

    return 0;
}
