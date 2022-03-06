#include <stdio.h>
int main(){
    int a,b,c,d;
scanf("%d\n%d",&a,&b);
if(a>=b)
{c=a+b;
    d=a-b;}
    else
    {c=a+b;
        d=b-a;}
    
    printf("%d\n%d",c,d);
    return 0;
}