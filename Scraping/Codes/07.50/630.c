#include <stdio.h>

void update(int *a,int *b)
 {
    int l,m;
    l=*a+*b;
    m=*b-*a;
    *a=l;
    *b=m ; 
}

int main()
 {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
