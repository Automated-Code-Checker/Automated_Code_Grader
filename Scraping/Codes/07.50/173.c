#include <stdio.h>

void update(int *a,int *b);
void update(int *pa,int *pb)

 {

    printf("%d\n",(*pa)+(*pb));
    printf("%d\n",(*pb)-(*pa));
    // Complete this functio
        
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d%d", &a, &b);
    update(pa, pb);
    

    return 0;
}
