#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int add,sub;
    add=(*a)+(*b);
    sub=(*a)^(*b);
    printf("%d\n",add);    
    printf("%d",sub);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}

