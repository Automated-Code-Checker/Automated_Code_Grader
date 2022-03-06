#include <stdio.h>

void update(int *pa,int *pb) {
    int temp=*pa;
    *pa=*pa+*pb;
    if(temp>*pb)
        *pb=temp-*pb;
    else
        *pb=*pb-temp;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", *pa,*pb);

    return 0;
}