#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    // Complete this function
	int a1 = *a + *b;
	int b1 = *a - *b;
	int b2;
	
		b2 = abs(b1);
	*a = a1;
	*b = b2;


}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}