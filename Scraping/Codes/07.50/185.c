#include <stdio.h>
#include<math.h>

void update(int *a,int *b) {
   int add = *a+*b;
    int sum = *a-*b;
    if(sum<=-1){
    sum = sum*sum;
    sum = sqrt(sum);
    }
    printf("%d\n",add);
    printf("%d\n",sum);
        
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d",&a,&b);
    update(pa, pb);
    
    return 0;
}
