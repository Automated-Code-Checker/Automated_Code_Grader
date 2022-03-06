#include <stdio.h>

    
     

    
    


int main() {
    int c,d;
    scanf("%d%d",&c,&d);
    int sum = c+d;
     int *e=&sum;
     int dif= d-c;
     int *f= &dif;
     printf("%d \n",*e);
     printf("%d",*f);
     return 0;

}
