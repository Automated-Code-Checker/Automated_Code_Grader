#include <stdio.h>

void update(int *a,int *b) {
    int anew,bnew;
    anew=*a+*b;
    bnew=*a-*b;
    if(bnew<0)
        bnew=bnew * (-1); 
    *a=anew;
    *b=bnew;// Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}