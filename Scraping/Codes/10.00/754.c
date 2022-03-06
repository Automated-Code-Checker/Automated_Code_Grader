#include <stdio.h>

void update(int *a,int *b) {
     int sum= *a + *b;
     int dif= abs(*a - *b);
    printf("%d\n",sum);
    printf("%d",dif);
    
        
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    

    return 0;
}