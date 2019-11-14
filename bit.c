#include<stdio.h>
#include<string.h>
int main()
{
	int i,count=0;
	char bitsdata[80];
	printf("Enter the bitsdata\n");
	scanf("%s",bitsdata);
	printf("The data before bit stuffing is %s\n",bitsdata);
	printf("The data after bit stuffing is :\n");
	printf("01111110");
	for(i=0;i<strlen(bitsdata);i++)
	{
		if(bitsdata[i]=='1')
			count++;
		else
			
			count=0;
		printf("%c",bitsdata[i]);	
		
		if(count==5)
		{
			printf("0");
			count=0;
		}
	}
	printf("01111110\n");
return 0;
}
