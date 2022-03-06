#include <stdio.h>
#include<stdlib.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    void update(int *x, int *y)
    {
        
        int d,c;
       d= abs(*x-*y);
       c= *x+*y;
        *pa=c;
        *pb=d;
        
    }
    
    scanf("%d %d", &a, &b);
  
    update(pa, pb);

    printf("%d\n%d", a, b);

    return 0;
}