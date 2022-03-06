#include <stdio.h>

void update(int n,int m) {
    // Complete this function 
       int c=m+n;
       int g=m-n;
        printf("%d\n%d", c,g);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    update(a, b);
   

    return 0;
}
