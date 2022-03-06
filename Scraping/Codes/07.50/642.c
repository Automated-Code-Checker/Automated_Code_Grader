#include <stdio.h>

void update(int *a,int *b) 
{
    int tempA;
    int tempB;
    tempA=*a;
    tempB=*b;
    *a = tempA+tempB;
    *b = tempB-tempA;
}
    

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
