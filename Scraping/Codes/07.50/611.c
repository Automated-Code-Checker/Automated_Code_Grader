#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int *temp;
    *temp = *a + *b;
    *b = *b - *a;
    *a = *temp;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", *(pa), *(pb));

    return 0;
}