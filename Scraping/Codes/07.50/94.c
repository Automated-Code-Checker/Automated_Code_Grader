#include <stdio.h>

void update(int *a,int *b) {
    int diff;
    
      int sum=(*a)+(*b);
      if (a>=b){
          diff=(*a)-(*b);
      }
      else{
          diff=(*b)-(*a);
      }
      
      printf("%d\n",sum);
      printf("%d",diff);
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    // printf("%d\n%d", a, b);

    return 0;
} 
