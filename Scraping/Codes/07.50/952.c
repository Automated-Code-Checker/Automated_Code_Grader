#include <stdio.h>

void update(int *a,int *b) {
    int c, d, e;
    c = *a + *b;
    d = *a - *b;
    if (d<0){
        e = d*-1;
    }
    printf("%d\n%d",c ,e);   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    return 0;
}
