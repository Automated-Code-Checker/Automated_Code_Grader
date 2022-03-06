#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int i,j;
    i=*a;
    j=*b;
    if(j>i)
    {
    *b=i-j;
    *b=-*b;
    }
    *a=i+j;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
