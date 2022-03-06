#include <stdio.h>

void update(int *a,int *b) {
    int *c;
    *(a)=*(a)+*(b);
    if(*(a)>*(b))
    {
        *(c)=2*(*b);
        *(b)=*(c)-*(a);
    }
      else
      {
          *(b)=*(a)-*(c);
      }
 // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

