#include <stdio.h>
#include <math.h> 



int  main() {
    int a, b;
    int *pa = &a, *pb = &b ,*pc ,*pd ;
    
    
    scanf("%d %d", &a, &b);
    *pc=*pa+(*pb);
    *pd=(*pb)-(*pa);
    printf("%d\n%d", *pc, *pd);
    return 0;
}
