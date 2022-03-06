#include <stdio.h>

void update(int *a,int *b) 
{
       
}

int main()
 {
    int a, b,ans;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    ans= *pa+*pb;
    printf("%d\n",ans);
    ans= *pb-*pa;
    printf("%d",ans);

    return 0;
}
