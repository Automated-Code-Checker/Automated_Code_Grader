#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function    
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    int ans=a+b;
    printf("%d\n",ans);
    
     
   {    int answe= a-b;
      printf("%d\n",-answe);} 

    return 0;
}
