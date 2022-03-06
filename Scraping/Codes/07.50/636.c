#include <stdio.h>

void update(int *a,int *b) {
   int temp;
    temp= *a + *b;//9
     *b= *b - *a;//1
     *a= temp;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
