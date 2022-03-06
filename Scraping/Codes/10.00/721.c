#include <stdio.h>
#include <math.h>
void update(int a,int b) {
    // Complete this function    
    int c,d,e;
    c=a+b;
    d=a-b;
    if(d<0)
    { e=-d;
     
    }else
    {   e=d;
     
    }
     printf("%d\n%d",c,e);
}

int main() {
    int a,b,c,d,e;
    //int *pa = &a, *pb = &b;
    
    scanf("%d\n%d", &a, &b);
    update(a,b);
   

    return 0;
}