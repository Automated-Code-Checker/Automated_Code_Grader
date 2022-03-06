#include <stdio.h>

void update(int *a,int *b) {
    int a2, b2;
    
    a2 = *a + *b;
    b2 = *a - *b;
    
    if(b2 < 0){
        b2 = b2*-1;
    }
    
    *a = a2;
    *b = b2;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}