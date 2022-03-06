#include <stdio.h>

void update(int *a,int *b) 
{

    int sum     = (*a)+(*b);
    int diffAbs = abs((*a)-(*b));
    
    *a=sum;
    *b=diffAbs;
    /*printf("%d\n",sum);
    printf("%d\n",diffAbs);*/
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}