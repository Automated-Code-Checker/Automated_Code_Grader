 #include<stdio.h>

int main(){
    int a,b;
    
    scanf("%d\n %d",&a,&b);
    int* x=&a;
    int* y=&b;
   int sum = *(x)+(*(y));
    int diffrence = *(y)- (*(x));
    printf("%d\n%d", sum, diffrence);
 

    
    
return 0;
}
