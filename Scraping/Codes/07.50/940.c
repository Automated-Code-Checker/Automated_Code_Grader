#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() 
{ int a, b,x,y;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    x=a+b;
    y=-(a-b);
    update(pa, pb);
    printf("%d\n%d", x, y);


    return 0;
}
