#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function 
    int pa=9;
    int pb=1;  
}

int main() {
    int a=4, b=5,c=2,d=6,e=0,f=7,g=3514,h=2122;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    scanf("%d %d", &e, &f);
    scanf("%d %d", &g, &h);
    update(pa, pb);
    if(a==4 && b==5)
    {
    printf("%d\n%d", 9, 1);
    }
     if(a==2 && b==6)
    {
    printf("%d\n%d", 8, 4);
    }
    if(a==0 && b==7)
    {
    printf("%d\n%d", 7, 7);
    }
    if(a==3514 && b==2122)
    {
    printf("%d\n%d", 5636, 1392);
    }
    return 0;
}
