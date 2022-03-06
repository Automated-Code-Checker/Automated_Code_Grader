#include <stdio.h>

int main() {
int a,b;
scanf("%d%d",&a,&b);
printf("%d",a+b);
    printf("\n");
if((a-b)<0)
{
printf("%d",-(a-b));
    
}
else
{
 printf("%d",a-b);   
}    

    return 0;
}