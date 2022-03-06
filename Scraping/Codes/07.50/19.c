#include <stdio.h>
#include<math.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
   a=(a+b);
   printf("%d\n",a);
   a=a-b;
    b=sqrt((a-b)*(a-b));
    
    printf("%d",b);

    return 0;
}
