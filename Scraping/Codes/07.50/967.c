#include <stdio.h>

void update(int *a,int *b) {
    int a1,b1;
    
    a1 = *a+*b;
    if(b>=a){
    b1 = (*b-*a);
    }
    else{ b1 = (*a - *b);}
    *a = a1;
    *b = b1;
    
        
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
