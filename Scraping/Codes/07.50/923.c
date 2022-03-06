#include <stdio.h>

void update(int *a,int *b) {
    int s,i;
    s = *a + *b;
    i = *b - *a;  
    *a = s;
    *b = i;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
