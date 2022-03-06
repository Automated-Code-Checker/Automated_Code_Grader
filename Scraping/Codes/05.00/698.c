#include<stdio.h>
int main() {
    int aa,bb,val,val1;
    int *a,*b;
 scanf("%x",&aa);
 scanf("%x",&bb);
a=&aa;
b=&bb;
val=*a+*b;
val1=(*a-*b);
val1=-1*val1;
printf("%d\n",val);
printf("%d",val1);
}
