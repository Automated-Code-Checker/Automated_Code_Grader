#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int temp = *a + *b;
    int temp2 = *a - *b;
    *a = temp;
    *b = temp2<0?-temp2:temp2;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}