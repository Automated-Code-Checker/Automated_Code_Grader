#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
//     int *pa = a; int *pb = b;
//     *pa = *a + *b;
//     *pb = (a>b)?(a-b):(b-a);
//     *a = *pa;
//     *b = *pb;
    int x = *a; int y = *b;
    *a = x + y; 
    *b = (x>y)?(x-y):(y-x);
 }

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}