#include <stdio.h>

int main() 
{
    int a,b,*pa,*pb,s,d;
    pa=&a;
    pb=&b;
    scanf("%d%d",&a,&b);
    s=((*pa)+(*pb));
    d= ((*pb)-(*pa)) ;
    printf("%d\n%d",s,d);
    return 0;
}
