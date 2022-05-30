#include<stdio.h>

int main() {
    int a, b;
    int c,d;
    scanf("%d %d", &a, &b);
    c=a+b;
    d=b%a;
    
    printf("%d\n%d", c,d);

    return 0;
}