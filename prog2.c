#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

void main()
{
	int i,n,j,count,framelen=0,zeroadded=0;
	int msg[100];
	int result[100];
	printf("Enter the number of bits\n");
	scanf("%d",&n);
	printf("Enter the bits\n");
	for(i=0;i<n;i++)
		scanf("%d",&msg[i]);
	result[0]=0;
	result[1]=1;
	result[2]=1;
	result[3]=1;
	result[4]=1;
	result[5]=1;
	result[6]=1;
	result[7]=0;
	j=8;
	for(i=0;i<n;i++)
	{
		if(msg[i]==0)
		{
			count=0;
			result[j++]=msg[i];
		}
		if(msg[i]==1)
		{
			if(count==5)
			{
				result[j++]=0;
				zeroadded++;
				result[j++]=msg[i];
				count=0;
			}
			else
			{
	
				result[j++]=msg[i];
				count++;
			}
		}
	}
	result[j++]=0;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=1;
	result[j++]=0;
	framelen=16+n+zeroadded;
	printf("Frame sent is\n");
	for(i=0;i<framelen;i++)
		printf("%d",result[i]);
	printf("\n");
}
