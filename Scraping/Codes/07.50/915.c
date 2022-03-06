#include <stdio.h>

void update(int *a,int *b)
 {
    int sum,diff;
    sum=(*a+*b); 
    printf("%d\n",sum);
    if(b>a) { 
    diff=(*b-*a);
    printf("%d",diff);}
    else {
    diff=(*a-*b);
    printf("%d",diff);}
}
int main() {
    int p, q;
    int*pa = &p, *pb = &q;
    
    scanf("%d\n %d", &p, &q);
    update(pa,pb);


    return 0;
}
