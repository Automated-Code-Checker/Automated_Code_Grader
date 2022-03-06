#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    
    int res1,res2;
        res1=*a+*b;
    res2=*a-*b;
    printf("%d",res1);
    if(res2<0)
        res2=res2*-1;
    printf("\n%d",res2);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
  

    return 0;
}