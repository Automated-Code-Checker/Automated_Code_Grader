#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum,ab;
    sum = *a + *b;
    ab = *a-*b;
     if(ab<0){
       ab=ab*-1;
     }
    *a = sum;
    *b = ab;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d\n", a, b);

    return 0;
}
