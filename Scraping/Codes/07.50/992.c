#include <stdio.h>

void update(int *a,int *b) {
    int c;
    if(a>=b)
    c=*a-*b;
    else
    c=*b-*a;
    *a+=*b;
    *b=c;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
