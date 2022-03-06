#include <stdio.h>
#include <stdio.h>

void update(int *a,int *b) {
    int n = *a+*b;
    int n1 = (*a-*b);
    if(n1<0)
    {n1 = -(n1);}
    *a = n ;
    *b = n1;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}