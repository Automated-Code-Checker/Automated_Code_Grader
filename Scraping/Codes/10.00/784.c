#include <stdio.h>

int main() {
    int a, b,c,d;
     scanf("%d%d", &a, &b);
    c=a+b;
    if(a>b)
        d=a-b;
    else
        d=b-a;
    
    printf("%d\n%d", c, d);

    return 0;
}