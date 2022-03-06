#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void update(int *a,int *b) {
    int c = *a;
    *a = *a+*b;
    if(c>*b)
    {
        *b = c-*b;
        *b = abs(*b);
    }
    else 
    {
        *b = c-*a;
        *b = abs(*b);
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
