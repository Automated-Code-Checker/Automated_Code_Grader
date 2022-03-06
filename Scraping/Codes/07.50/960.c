#include <stdio.h>
void increment(int *v) {
            (*v)++; }
int main() {
int a,b;
scanf("%d",&a);
scanf("%d",&b);
int* pa=a+b;
int* pb=b-a;
printf("%d",pa);
printf("\n%d",pb);
    return 0;
}
