#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int *p1,*p2;
    p1=&a;
    p2=&b;
    int c=*p1+*p2;
    int d=*p2-*p1;
    printf("%d \n",c);
    printf("%d",d);

    return 0;
}
