#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
    int a, b;
    int sum, mod;
    
    scanf("%d", &a);
    scanf("%d", &b);

    sum = a+b;
    mod = abs(a-b);
    printf("%d\n%d", sum, mod);
    return 0;
}