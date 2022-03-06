#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void update(int *a,int *b) {
    // Complete this function    
    (*a)=(*a)+(*b);
    return a;
    (*b)=abs((*a)-(2*(*b)));
    return b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

