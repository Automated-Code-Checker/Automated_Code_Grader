#include<stdio.h>
int main()
{
  int a,b,sum,difference;
  scanf("%d",&a);
  scanf("%d",&b);
  sum=a+b;
  difference=a-b;
  difference=-difference;
  printf("%d",sum);
  printf("\n%d",difference);      
}
