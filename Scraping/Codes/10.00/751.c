#include <stdio.h>

void update(int *a,int *b) {
    
    int tempSum = *a + *b;
    int tempDiff = *a - *b;
    if(tempDiff < 0){
        tempDiff += 0 - tempDiff * 2;
    }
    *a = tempSum;
    *b = tempDiff;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}