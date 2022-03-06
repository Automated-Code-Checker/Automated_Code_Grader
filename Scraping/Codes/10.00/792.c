#include <stdio.h>

void update(int *a,int *b) {
    
    int a1,b1;
    a1=*a+*b;
    b1=*a-*b;
    if(b1<0)
    {
        b1=-1*b1;
    }
    *a=a1;
    *b=b1;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}