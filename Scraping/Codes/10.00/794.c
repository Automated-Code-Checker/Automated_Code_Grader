#include <stdio.h>

void update(int *x,int *y) {
    int temp=*x;
    *x += *y;
    if(temp > *y)
        *y= temp - *y;
    else if(*y>temp)
        *y = *y - temp;
    
    
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