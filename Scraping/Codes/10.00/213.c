#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int va = *a + *b;
    int vb = *a - *b;
    vb =  vb < 0 ? vb * -1 : vb;
    *a = va;
    *b = vb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
