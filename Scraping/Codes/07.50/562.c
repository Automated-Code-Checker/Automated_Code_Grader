#include <stdio.h>

void update(int *a,int *b) {
    
    int x,z;
    

    if(a>b)
    {
       x=*a+*b;
       z=*a-*b;
    
    }
    else {
        x=*a+*b;
        z=*b-*a;
        
    }
        
    *a=x;
    *b=z;   
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
