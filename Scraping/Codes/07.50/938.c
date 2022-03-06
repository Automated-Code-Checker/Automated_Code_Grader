#include <stdio.h>

int update(int *a,int *b) { int  sum;
   sum=*a+*b;
     return sum;   
}
int develop(int *a,int *b)
{
    int sub;
    sub=*b-*a;
    return sub; 
}

int main() {
    int a,b,c,d;
    

    scanf("%d %d", &a, &b);
    c=update(&a, &b);
    printf("%d\n", c);
    d=develop(&a,&b);
    printf("%d",d);

    return 0;
}
