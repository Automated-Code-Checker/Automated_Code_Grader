#include <stdio.h>
#include <stdlib.h>
void update(int *a,int *b);
void update(int *a,int *b) {
    int sum,dif;
    sum=*a+*b;
    dif =*b-*a;
    printf("%d\n%d", sum, dif); 
}

int main() {
    int a, b,sum,dif;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);

    return 0;
}
