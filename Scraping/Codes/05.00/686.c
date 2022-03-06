#include <stdio.h>

void update(int *pa,int *pb) {
    int *e;
   *e=*pa; 
    *pa=*pa+*pb;
      *pb=(*pa>*pb)?(*e-*pb):(*pb-*e);
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

