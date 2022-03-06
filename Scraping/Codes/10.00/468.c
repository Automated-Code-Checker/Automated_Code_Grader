#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    
    if (a && b)
    {
        int tmpA = *a;
        int tmpB = *b;
        
        *a = (tmpA+tmpB);
        *b = (tmpA > tmpB) ? (tmpA-tmpB) : (tmpB-tmpA);
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