#include <stdio.h>

void update(int *a,int *b) {
    int t=*a;
    int t2=*b;
    *a=t+ t2;
    if(t>t2)
    {
        *b=t-t2;
    }
    else
    {
        *b=t2-t;
    }
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