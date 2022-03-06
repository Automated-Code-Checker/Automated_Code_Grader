#include <stdio.h>

void update(int a,int b, int *sum, int *dif) {
    int s,d;
    *sum = a + b;
    *dif = -(a - b);
}

int main() {
    int a , b ;
    scanf("%d %d",&a,&b);
    int sum,dif;
    
    update(a,b,&sum,&dif);
    printf("%d\n%d", sum, dif);

    return 0;
}
