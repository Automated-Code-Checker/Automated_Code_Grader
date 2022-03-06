#include <stdio.h>
#include<math.h>

void update(int *a,int *b) {
    int c;
    // Complete this function 
    c=*a;
    *a=(*a)+(*b);
    *b=-1*((c)-(*b));
}

int main() {
    int a, b,c;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
    
    
    return 0;
}

