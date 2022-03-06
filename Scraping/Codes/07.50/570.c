#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    *pa=a+b; 
    *pb=(2*(b)-*pa); //a=9
  //  *pb=(b-a);    //=1
    
    printf("%d\n%d", a, b);

    return 0;
}
