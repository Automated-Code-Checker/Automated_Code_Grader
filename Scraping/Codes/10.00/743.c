#include <stdio.h>

void update(int *a,int *b) {
    int a1,b1;
   
    a1=*a+*b;
    b1=(*a)-(*b);
        if(b1<0)
b1=-b1;
    *a=a1;
    *b=b1;


    // Complete this function    
}

int main() {
    int a, b,temp;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}