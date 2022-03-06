#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b,res,ans;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    res=*pa+*pb;
    ans=*pb-*pa;
    
    printf("%d\n%d",res ,ans );

    return 0;
}
