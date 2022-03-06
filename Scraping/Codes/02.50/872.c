#include <stdio.h>

int main()
{
int a=0,b=7,sum,diff;
int *ptr1,*ptr2;
ptr1=&a;
ptr2=&b;
sum=*ptr1 + *ptr2;
diff=abs(*ptr1 - *ptr2);
printf("%d\n",sum);
printf("%d\n",diff);

}

