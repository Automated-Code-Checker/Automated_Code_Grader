#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int x; int y;
    x = *a+ *b;
    y =*b-*a;
    *a = x;
    *b = y;  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
