#include<iostream>
#include<string.h>
int main()
{
	int i,n,flag=0;
	char str[17];
	printf("Enter the string:");
	gets(str);
	n=sizeof(str);
	
	for(i=1;i<n;i++)
	{
		
		if (n % i != 0) {
	      flag = 1;
			if(i%10==3){
			str[i]='$';
		 }
	    }
		else{
			continue;
		}
	}
	for(i=0;i<n;i++){
		printf("%c", str[i]);
	}
	
}
