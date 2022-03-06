#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum = 0;
    int sub = 0;
    sum = *a+*b;
    
    if(a>b)
    {
        sub = (*a)-(*b);
        *b = sub;
        *a = sum;
    }    
    else
    {
        sub = (*b)-(*a);
        *b = sub;
        *a = sum;        
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
