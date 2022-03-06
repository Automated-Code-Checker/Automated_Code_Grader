#include <stdio.h>

int update(int *a,int *b) 
{
    {
     *a = *a + *b;
    return *a;
    }
      *b = *a - *b;
      if (*b < 0)
        *b = *b * (-1);
      return *b;   
}

int main()
{
    int x, y;
    scanf("%d %d", &x, &y);
    update(&x, &y);
    printf("%d\n%d", x, y);
    return 0;
}

