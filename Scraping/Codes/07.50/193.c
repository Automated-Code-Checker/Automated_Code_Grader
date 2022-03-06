#include <stdio.h>

int main()
{
    int num1, num2, sum , diff;
    int *ptr1, *ptr2;

    ptr1 = &num1; // ptr1 stores the address of num1
    ptr2 = &num2; // ptr2 stores the address of num2
    scanf("%d %d", ptr1, ptr2);

    sum = *ptr1 + *ptr2;
    if(ptr1>ptr2)
    {
     diff=*ptr1-*ptr2;
    }
    else {
     diff=*ptr2-*ptr1;
    }
    printf("%d\n%d", sum , diff);

    return 0;
}
