#include<stdio.h>
void update(int *a,int *b);
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    update(&a,&b);
    return 0;
}
void update(int *a,int *b){
    int A,B;
    A=*a+*b;
    B=*b-*a;
    printf("%d\n",A);
    printf("%d\n",B);
}
