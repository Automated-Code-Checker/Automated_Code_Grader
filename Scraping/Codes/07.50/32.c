#include <stdio.h>

void update(int *x,int *y) {
    // Complete this function 
    *x= *x+*y;
    if(x>y)
    {
        *y=*x-*y-*y;
    }
    else
        *y=*y-*x+*y;
   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}
