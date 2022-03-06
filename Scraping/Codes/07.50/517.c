#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int m,n;
    m = *a + *b;
    printf("%d\n",m);
    n = *b - *a;  
    printf("%d\n",n);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}
