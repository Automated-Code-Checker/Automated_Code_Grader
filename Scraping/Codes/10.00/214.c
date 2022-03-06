#include <stdio.h>

void update(int *a,int *b) {
    int tmp1 = *a;
    int tmp2 = *b;
    *a = tmp1+tmp2;
    *b = tmp1-tmp2;
    if(*a<0){
        *a = (*a)*(-1);
    }
    if(*b<0){
        *b = (*b)*(-1);
    }
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
