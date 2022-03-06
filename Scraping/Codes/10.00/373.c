#include <stdio.h>

void update(int *a,int *b) {
    int s = *a + *b;
    int m = *a - *b;
    if (m < 0) m = -m;
    *a = s;
    *b = m;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}