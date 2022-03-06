#include <stdio.h>

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

void update(int *a, int *b)
{  
  *a = *a + *b;
  *b = *a -((*b)+(*b)) ;
}
