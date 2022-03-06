#include <stdio.h>
void update(int*,int*);
int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
    void update(int *c,int *d)
    {
        int j,k;
        j=*c;
        *c=*c+*d;
        *d=j-*d;

    }

