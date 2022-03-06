#include <stdio.h>

/*void update(int *a,int *b) {
    int n1,n2;
    *a=&n1;
    *b=&n2;
    n1=a+b;
    if(a>b){
        n2=a-b;
    }
    else if(a<=b)
    {
        n2=b-a;
    }
    printf("%d\n%d",n1,n2);
    
    // Complete this function    
}*/

int main() {
    int a, b,n1,n2;
    int *pa = &a, *pb = &b;
    
    scanf("%d\n%d", &a, &b);
    n1=a+b;
    if(a<=b)
        n2=b-a;
    else if(a>b)
        n2=a-b;
    printf("%d\n%d", n1, n2);

    return 0;
}