#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,c,d,*pa,*pb;
     
    scanf("%d %d", &a, &b);
    pa = &a;
    pb = &b;
    c= *pa + *pb;
    d= (*pa - *pb) * -1;
    printf("%d\n%d", c, d);

    return 0;
}
