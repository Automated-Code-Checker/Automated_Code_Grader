#include <stdio.h>

int main()
{
    int angka1, angka2, hasil1, hasil2;
    scanf("%d", &angka1);
    scanf("%d", &angka2);
    
    hasil1 = angka1 + angka2;
    hasil2 = angka1 - angka2;
    
    printf("%d\n", hasil1);
    printf("%d\n", hasil2);
    return 0;
}