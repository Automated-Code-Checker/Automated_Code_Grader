#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
   int *a,*b,s,d,o,t;
   scanf("%d%d",&o,&t);
   a=&o;
   b=&t;
   s=*a+*b;
   d=*b-*a;
   printf("%d\n%d",s,d);
    

    return 0;
}
