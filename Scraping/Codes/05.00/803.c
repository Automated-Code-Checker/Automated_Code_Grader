#include <stdio.h>

void update(int *a,int *b) {
    
    // Complete this function    
}

int main() {
    int a, b,c;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    c=a;
    a=a+b;
    
    if(c<<b)
    {
        b=b-c;
    }
    else {
    {
        b=c-b;
    }
    }
    printf("%d\n%d", a, b);

    return 0;
}
