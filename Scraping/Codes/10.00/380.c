#include <stdio.h>

void update(int *pa,int *pb) {
    // Complete this function
    int sum=0;
    int diff=0;
    int diffe=0;
    sum=(*pa)+(*pb);
    diff=(*pa)-(*pb); 
    diffe=abs(diff);
    printf("%d\n%d",sum,diffe);
    //return diffe;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(&a,&b);
    //printf("%d\n%d", a, b);

    //return 0;
}