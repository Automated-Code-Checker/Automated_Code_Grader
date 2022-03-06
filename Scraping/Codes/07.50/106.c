#include <stdio.h>

void update(int *a,int *b) {  
}

int main() {
    int a=4, b=5,a1,b1;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    a1=a+b;
    b1=b-a;
    update(pa, pb);
    printf("%d\n%d", a1,b1);

    return 0;
}
