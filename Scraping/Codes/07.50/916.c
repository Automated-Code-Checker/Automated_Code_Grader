#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int sum=*a+*b;
    printf("%d \n",sum);
    int abs=*b-*a;
    printf("%d\n",abs);   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    

    return 0;
}
