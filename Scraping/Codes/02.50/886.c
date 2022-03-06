#include <stdio.h>

int main() {
    int a, b,c;
    
    
    scanf("%d %d", &a, &b);
    c=a;
    a=c+b;
    b=c-b;
    printf("%d\n%d", a, b);

    return 0;
}

