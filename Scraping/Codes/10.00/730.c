#include <stdio.h>
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    if(a>b)
    printf("%d\n%d", a+b,a-b);
    else
        printf("%d\n%d",a+b, b-a);
    return 0;
}