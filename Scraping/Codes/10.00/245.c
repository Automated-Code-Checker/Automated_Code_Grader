#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    int *temp=(*a)+(*b);
    int *temp1=(*a)-(*b);
   // printf("\ncheck :%d %d\n",*a,*b);
    *a=temp;
    *b=temp1;
  //  printf("\ncheck1 :%d %d\n",*a,*b);
    if(*a<0)
    {
        (*a)*=-1;
    }
     if(*b<0)
    {
        (*b)*=-1;
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