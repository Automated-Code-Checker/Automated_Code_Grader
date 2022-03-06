#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int sum, sub;
    sum = *a + *b ;
    
    if (a > b){
        sub = *a - *b ;
    }
    else if (b>a){
        sub = *b - *a;
    }
    else{
        sum = 0;
    }
    *a = sum;
    *b = sub;
       
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
