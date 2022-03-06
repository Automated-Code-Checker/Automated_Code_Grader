#include <stdio.h>

void update(int *a,int *b) {
    int s,d;
     s=*a+*b;
     if(a>b)
     {
         d=*a-*b;
     }  
     else {
         d=*b-*a;
     }
     
     *a=s;
     *b=d;
     
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
