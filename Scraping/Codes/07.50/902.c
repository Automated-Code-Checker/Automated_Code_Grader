#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int x,y,p;
    p=*a;
    x=*a+*b;
    *a=x;
    if(p>b)
    {
       y=p-*b;
       *b=y;
    }
    else
    {
        y=*b-p;
        *b=y;
    }   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
