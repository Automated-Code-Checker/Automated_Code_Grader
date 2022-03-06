#include <stdio.h>
#include <math.h>
/*void update(int *a,int *b) {
    int *t1,x,y;
    t1=a;
    *a=*a+*b;
    if(a>b)
        *b=*t1-2*(*b);
    else
        *b=2*(*b)-*t1;
}*/

int main() {
    int a, b,c,d;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    //update(pa, pb);
    c=a+b;
    if(a<b)
        d=b-a;
    else
        d=a-b;
    printf("%d\n%d", c, d);

    return 0;
}