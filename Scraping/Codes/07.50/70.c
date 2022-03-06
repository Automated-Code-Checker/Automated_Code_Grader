#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    
    scanf("%d %d", &a, &b);
    
    printf("%d", a+b);
    if(a>b){
        printf("%d",a-b);
    }
    else{
        printf("\n%d",b-a);
    }

    return 0;
}
