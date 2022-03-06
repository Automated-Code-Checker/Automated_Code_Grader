#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
     printf("%d\n%d",(*a)+(*b), abs((*a)-(*b)));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;  
    scanf("%d %d", &a, &b);
    update(pa, pb);
    return 0;
}