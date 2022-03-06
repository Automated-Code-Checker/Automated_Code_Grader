#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
    printf("%d\n",(*a+*b));
    if(*a>*b)
    printf("%d",(*a-*b));
  else
      printf("%d",(*b-*a));
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    //printf("%d\n%d", a, b);

    return 0;
}