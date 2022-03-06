#include <stdio.h>

void update(int *pa,int *pb,int a,int b){
    int sum=a+b,diff=b-a;
    *pa=sum;
    *pb=diff;
}

int main() {
    int *pa,*pb,a,b;
    scanf("%d %d", &a, &b);
    update(pa,pb,a,b);
    printf("%d\n%d",*pa,*pb);

    return 0;
}
