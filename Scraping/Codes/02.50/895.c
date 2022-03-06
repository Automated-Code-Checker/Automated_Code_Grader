#include <stdio.h>
#include<math.h>
int main()
{
        int a,b,a1,b1;
        scanf("%d",&a);
        scanf("%d",&b);
        a1=a+b;
        b1=(a1-b1);
        printf("%d\n",a1);
        if(b1>0)
        printf("%d\n",b1);
        else
        printf("-%d\n",b1);
}

