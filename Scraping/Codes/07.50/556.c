#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    scanf("%d",&*a);
    scanf("%d",&*b);
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    
    printf("%d\n%d", a+b, b-a);

    return 0;
}
