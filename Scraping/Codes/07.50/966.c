#include <stdio.h>

void update(int *a,int *b) {
    printf("%d\n",(*a+*b)); 
    if(a>b)
    printf("%d",(*a-*b));
    else if(b>a)
    printf("%d",*b-*a);   
}

int main() {
   
   int a,b;
   scanf("%d\n",&a);
   scanf("%d",&b);
   update(&a,&b);
   
    return 0;
}
