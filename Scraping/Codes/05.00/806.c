#include <stdio.h>

void update(int *a,int *b)
{
    *a=*a+*b;
if(*a>*b)
    
     {
         *b=-*a+*b+*b;
     }
     else 
     {
       *b=-*b-*b+*a;  
     }
     
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}