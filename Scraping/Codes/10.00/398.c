#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    static int auxA = 0;
    auxA = *a;
    static int auxB=0;
    auxB = *b;
    *a = auxA + auxB;
    *b = auxA - auxB;
    
    if(*b < 0){
        *b *=-1;
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}