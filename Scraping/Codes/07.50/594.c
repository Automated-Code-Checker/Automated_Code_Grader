#include <stdio.h>
#include<math.h>

int main(){
    int a,b,*pa,*pb;
    int sum,sub;
    scanf("%d %d",&a,&b);
    pa = &a;
    pb = &b;
    
    sum = *pa + *pb;
    printf("%d",sum);
    
    printf("\n");
    
    sub = (*pa-*pb)*-1;
    printf("%d",sub);
    
    return 0;
    
}
