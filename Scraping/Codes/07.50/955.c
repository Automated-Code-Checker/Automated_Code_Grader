#include <stdio.h>

void update(int *a,int *b) {
    int c,d;
    c = *a + *b; 
    d = -(*a - *b);
    printf("%d\n",c);
    printf("%d\n",d);   
}

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    update(&a, &b);
    return 0;
}
