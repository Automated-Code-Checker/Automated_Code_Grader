#include <stdio.h>

void update(int *a,int *b) {
    int tmpa=*a, tmpb=*b;
    *a=tmpa+tmpb;
    *b=fabs(tmpa-tmpb);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}