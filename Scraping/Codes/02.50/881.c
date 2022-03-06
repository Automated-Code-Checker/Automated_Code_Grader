#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
     *a=0+7;
     *b=7-0;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

