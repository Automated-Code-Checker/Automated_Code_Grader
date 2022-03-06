#include<stdio.h>

int main(){
    int a;
    int b;
   int* ptr = &a;
   int* ptr2 = &b; 
   scanf("%d %d", &a , &b);
   printf( "%d\n", *ptr2+*ptr);
   printf( "%d\n",*ptr2-(1**ptr));
    
    return 0;
}
