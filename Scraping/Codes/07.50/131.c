#include<stdio.h>
#include<math.h>
main()
{
    int a,b,x,y;
    scanf("%d%d",&a,&b);
    x=a+b;
    y=a-b;
    if(y<=0)
    {
        printf("%d\n%d",x,-1*y);
    }
    if(y>0)
    {
        printf("%d%d",x,y);
    }
    
}
