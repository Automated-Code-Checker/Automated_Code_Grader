#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    printf("%d\n",*a+*b);
    int c =*a-*b;
    if(c<0)
    {
        c=-1*c;
    }
    printf("%d",c);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    

    return 0;
}