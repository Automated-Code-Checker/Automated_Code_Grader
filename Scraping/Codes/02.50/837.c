#include <stdio.h>
    void update(int *a,int *b)
    {
    int c = *a;
    *a = *a + *b;
   if(c > *b)
   {
       return  (c - *b);
   }
        else if(c == *b)
        {
            return 0;
        }
    else
    { 
        return (*b - c);
    }
}

int main()
 {
    int a,b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa,pb);
    printf("%d\n%d",a,b);
    return 0;
}