#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,sum,dif;
    scanf("%d",&a);
    scanf("%d",&b);
    sum=a+b;
    dif=sqrt((a-b)*(a-b));
    printf("%d\n",sum);
    printf("%d",dif);
    return 0;                                                                            
}
