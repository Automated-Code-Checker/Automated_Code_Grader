#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int temp=a+b;
    b=b-a;
    printf("%d\n%d", temp, b);
    return 0;
}
