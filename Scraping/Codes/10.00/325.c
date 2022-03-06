#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int c=*a+*b;
    *b=*a-*b;
    if(*b<0)
    {
        *b=-(*b);
        
    }
    *a=c;
}

int main() {
    int a, b,c;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}