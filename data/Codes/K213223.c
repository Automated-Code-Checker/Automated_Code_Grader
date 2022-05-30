#include<stdio.h>
#include <string.h>
int main()
{
	char str[100] = "This is a string.";
	int i;
	for ( i = 2 ; i < strlen(str) ; i++ )
	{
		int counter = 0;
		int temp = i - 1;
		while ( temp > 1 )
		{
			if ( i%temp == 0 )
				counter++;
			temp--;
		}
		if ( counter == 0 )
		{
			counter = i;
			while ( counter > 10 )
			{
				counter %= 10;
			}
			if ( counter == 3 )
			{
				str[i] = '$';
			}
			
		}
	}
	puts(str);
}
