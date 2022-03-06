#include <stdio.h>

void update(int *a,int *b) {
    int temp=*a;
    *a=*a+*b;
        
    *b=*a-temp-temp;
        
    // Complete this function    
}

int main() {
    int a, b,temp;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
