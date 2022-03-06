#include <stdio.h>
#include<math.h>

void update(int *a,int *b) {
    int x,y;
    x=*a+*b;
    y=abs(*a-*b);
    printf("%d\n%d\n",x,y);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}