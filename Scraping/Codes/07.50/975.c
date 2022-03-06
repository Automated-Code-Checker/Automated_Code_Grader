#include <stdio.h>
void update(int *a,int *b);
int main()
{
    int a,b,c,d;
    scanf("%d %d",&a,&b);
    c=a+b;
    printf("%d\n",c);
    d=a-b;
    if(d<0){
        d=d*(-1);
    printf("%d\n",d);}
    
    
}

