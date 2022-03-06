#include <stdio.h>

void update(int *a,int *b) {
    int t;
    t = *a;
    *a = *b;
    *b = t;
      
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a +b, a - b);

    return 0;
}
