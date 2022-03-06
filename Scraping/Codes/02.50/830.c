#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    
    //printf("%d and %d", *a, *b);
    
    int a_prime=0;
    int b_prime=0;
    
    a_prime = *a + *b;
    b_prime = *a - *b;
    
    *a = a_prime;
    *b = b_prime;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}