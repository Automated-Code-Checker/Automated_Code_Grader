#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function  
    int n1 = *a,n2 = *b;
    *a = n1+n2;
    if (n1 >= n2){
        *b = n1-n2;
    }
    else{
        *b = n2-n1;
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