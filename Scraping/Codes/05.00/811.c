#include <stdio.h>

void update(int *a,int *b) {
    int x = *a, y = *b;
     *a = x+y;
     if(*a>*b){
        *b = y-x;
     }
     else {
        *b = x-y;
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
