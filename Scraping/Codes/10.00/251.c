#include <stdio.h>

void update(int *pa,int *pb) {
    int a = *pa;
    int b = *pb;
    int t = a+b;
    b = a-b;
    if(b < 0){
        b = -b;
    }
    a = t;
    *pa = a;
    *pb = b;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}