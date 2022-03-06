#include <stdio.h>
//#include<math.h>
int update(int *a,int *b) {
    // Complete this function
    int *c,*d;
    *c=(*a)+(*b);
    if(*a>*b)
      *d=*a - *b;
    else
      *d=*b - *a;  
    return *c;
    return *d;
    //printf("%d\n%d", c, d);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    int c=update(pa,pb);
    int d=update(pa,pb);
    printf("%d\n%d", c, d);

    return 0;
}