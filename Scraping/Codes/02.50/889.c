#include <stdio.h>

int update(int *f,int *g)
{
    int **c=&f,**d=&g;
    **c=*f+*g;
    return(c);
    **d=*f-*g;
    return(d);
}

int main()
 {
    int a, b;
     scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d",a,b);
    return 0;
}

