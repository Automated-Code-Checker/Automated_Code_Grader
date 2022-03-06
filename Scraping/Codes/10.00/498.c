#include <stdio.h>
#include <stdlib.h>

void update(int *a,int *b) {
    int temp = *a;
    int temp2 = *b;
    *a = temp+temp2;
    *b = abs(temp-temp2);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}