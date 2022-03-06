#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    
   
}

int main() {
    int a, b,c,d;
    scanf("%d\n%d", &a, &b);
    c=a+b;
    d=b-a;
    
     int *pa = &c, *pb = &d;
    
    void update(pa, pb);
    printf("%d\n%d", c, d);

    return 0;
}
