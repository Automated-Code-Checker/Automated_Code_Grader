#include <stdio.h>

void update(int *a,int *b) {
    int y = *a + *b;
    int x = *b - *a; 
    printf("%d\n%d",y,x);     
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%i %i", &a, &b);
    update(pa, pb);
    // printf("%d \n%d", a, b);
 
    return 0;
}
