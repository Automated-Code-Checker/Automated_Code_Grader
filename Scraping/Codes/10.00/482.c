#include <stdio.h>

void update(int *a,int *b) {
    int x=*a;
    int y=*b;
    if(*a>*b)
      *b=*a- *b;
     else
         *b=*b- *a;
    *a=x+y;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}