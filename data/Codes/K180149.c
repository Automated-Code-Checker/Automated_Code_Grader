#include <stdio.h> 

int main(){
	
	
	char s[17]= {'T','h','i','s',' ','i','s',' ','a',' ','s','t','r','i','n','g','.'};
	
	for(i=0;i<17;i++){
		
		if(i==3 || i%10==3){
			s[i]='$';
		}
	}
	
	
}