#include <stdio.h>

void update(int *a,int *b) {
    int temp=*a,temp2=*b;
    *a=temp+temp2;
    *b=temp-temp2;
    return *a,*b;  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

