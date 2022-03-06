#include <stdio.h>

void update(int *a,int *b) 
{
    //int A = *a;
    //int B = *b;
    //A += B;
    //B = abs(A - B);
    
     *a += *b;
    // *b = abs(*a - *b);   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

