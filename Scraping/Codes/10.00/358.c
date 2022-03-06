#include <stdio.h>

void update(int *a,int *b) {
    int as=(*a)+(*b);
    int bs;
    if(*a<*b){
        bs=(*b)-(*a);
    }
    else{
        bs=(*a)-(*b);
    }
    
    *a=as;
    *b=bs;
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}