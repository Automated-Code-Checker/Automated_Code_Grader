#include <stdio.h>

void update(int *a,int *b) {
    int temp1=*a,temp2=*b;
    int s,d;
    *a=temp1+temp2;
    if (temp1>temp1){
        b=temp1-temp2;
    }
    else{
        *b=temp2-temp1;
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
