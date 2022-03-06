#include <stdio.h>
#include <math.h>
#include<stdlib.h>
int  update(int* pa,int* pb) 
{
    // Complete this function 
    int temp=*pa;
   return *pa=temp+*pb,*pb=abs(temp-*pb);
  
    
    
}

int main() {
    int a, b;

    
    scanf("%d %d", &a, &b);
        int *pa = &a, *pb = &b;
    update(&*pa,&*pb);
    printf("%d\n%d", *pa, *pb);

    return 0;
}