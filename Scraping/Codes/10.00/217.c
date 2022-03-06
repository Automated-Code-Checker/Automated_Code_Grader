#include <stdio.h>
int main() {
    int a[4];    
    scanf("%d %d", &a[0], &a[1]);
    a[2]=a[0]+a[1];
    a[3]=a[0]-a[1];
    printf("%d\n",a[2]);
    if(a[3]<0)
        printf("%d",-a[3]);
    else
        printf("%d",a[3]);
    return 0;
}
