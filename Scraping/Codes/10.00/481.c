#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int a_ = (*a)+(*b);
    (*b) -=(*a);
    if((*b)<0)
        (*b) *=-1;
    (*a)=a_;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}