#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int temp;
    printf("%d\n",*a+*b);
    temp=*a-*b;
    temp = (temp<0) ? temp*-1 : temp*1;
    printf("%d\n",temp);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
 

    return 0;
}