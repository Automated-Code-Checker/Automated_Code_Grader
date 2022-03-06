#include <stdio.h>
#define max(a, b) ((a>b)?a:b)
#define min(a, b) ((a>b)?b:a)

void update(int *a,int *b) {
    int c = *a + *b;
    int d = max(*a, *b) - min(*a, *b);
    *a = c;
    *b = d;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}