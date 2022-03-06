#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,s,p;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    s=a+b;
    p=b-a;
    printf("%d\n%d", s, p);

    return 0;
}
