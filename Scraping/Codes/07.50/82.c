#include <stdio.h>

void update(int *a,int *b) {
 
     int c = *a+*b ;
       printf("%d\n",c);
     int d = *b - *a;
       printf("%d\n",d);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    return 0;
}
