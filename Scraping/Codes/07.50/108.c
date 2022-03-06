#include <stdio.h>

void update(int *X,int *Y) 
{int g=*X;
    *X=*X+*Y;
    *Y=*Y-g;
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
