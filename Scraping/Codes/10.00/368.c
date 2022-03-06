#include <stdio.h>
#include <math.h>
void update(int *a,int *b) {
    // Complete this function    
    int *pa,*pb;
    int n1,n2;
        n1=*a;
    n2=*b;
    pa=&n1;
    pb=&n2;
   *a= (*pa)+(*pb);
    *b=abs((*pa)-(*pb));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}