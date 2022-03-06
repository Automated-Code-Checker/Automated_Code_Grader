#include <stdio.h>

void update(int *a,int *b) {
   int sum=0,diff=0;
   sum=sum+*a+*b;
   diff=*b-*a;
   printf("%d\n",sum);
   printf("%d",diff);    
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    update(&a,&b);
    return 0;
}
