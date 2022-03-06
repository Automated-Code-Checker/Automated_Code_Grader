#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    //int *c = (int)*a, *d = (int)*b;
    if(*a < *b)
    {
        *a = *a + *b;
        *b = (*a - *b) - *b; 
        *b = -*b;
    }
    else
    {
        *a = *a + *b;
        *b = (*a - *b) - *b;
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