#include <stdio.h>

void update(int *pa,int *pb) {

  *pa=*pa+*pb;
  if(*pa>*pb)
    {
        *pb=*pb+*pb-*pa;
    
    }
 else{
     *pb=*pa-*pb-*pb;
 }

}

int main() {
    int a, b;
    int *pa,*pb;
    
    scanf("%d %d", &a, &b);
    update(&a, &b);
    printf("%d\n%d", a, b);

    return 0;
}

