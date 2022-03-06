#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int x = *a;
    int y = *b;
    if(x > y) {
        *b = x - y;
    }
    else {
        *b = y -x;
    }
    *a = x + y;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}