#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void update(int *m,int *n) {
    int temp,temp1;
    temp = *m;
    temp1 = *n;
    
    *m = temp+temp1;
    
    *n = abs(temp-temp1);
    
}

int main() {
    int m, n;
    int *pa = &m, *pb = &n;
    
    scanf("%d %d", &m, &n);
    update(pa, pb);
    printf("%d\n%d", m, n);

    return 0;
}