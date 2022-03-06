#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int aux1 = *a , aux2 = *b; 
    int aux = aux1 - aux2;
    *a = *a + *b;
    *b = abs(aux);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d\n%d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}