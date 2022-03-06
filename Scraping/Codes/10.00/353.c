#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function   
    int temp_a = *a;
    int temp_b = *b;
    int sub_ab = *a - *b;
    
    *a = temp_a + temp_b;
    if(sub_ab >= 0)
        *b = sub_ab;
    else
        *b = -sub_ab;
    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}