#include <stdio.h>

void update(int *m1,int *m2) 
{
    int s1,s2;
    s1 = *m1 + *m2;
    s2 = *m1 - *m2;
    *m1 = s1;
    *m2 =-s2; 
}

int main() 
{
    int m1, m2;
    int *pa = &m1, *pb = &m2;
    
    scanf("%d %d", &m1, &m2);
    update(pa, pb);
    printf("%d\n%d", m1, m2);

    return 0;
}
