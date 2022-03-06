#include <stdio.h>

void update(int *a,int *b) {
   *a=*a+*b; // Complete this function    
}

int main() {
    int a, b;
   
    
    scanf("%d %d", &a, &b);
    update(&a,&b);
    printf("%d\n%d", a, b);

    return 0;
}