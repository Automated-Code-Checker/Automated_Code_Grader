#include <stdio.h>

void update(int *a,int *b) {
   int *c,diff;
    *c=*a;
    *a=*a+*b;
    diff=*b-*c;
    if(diff<0){
        diff=-diff;
    }
    *b=diff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}