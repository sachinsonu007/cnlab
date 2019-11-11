#include<stdio.h>
#include<stdlib.h>
#define min(x,y)(x>y)?y:x

void main()
{
	int orate,cap,drop=0,inp[10]={0},ch,nsec,x,count=0,i;
	printf("Enter the bucket size : ");
	scanf("%d",&cap);
	printf("\nEnter the output rate : ");
	scanf("%d",&orate);
	do
	{
		printf("\nEnter the number of packets coming at second %d : ",i+1);
		scanf("%d",&inp[i]);
		if(inp[i]>cap)
		{
			printf("\nBucket overflow \nPacket Discarded");
			exit(0);
		}
		i++;
		printf("\nEnter 1 to continue and 0 to quit : ");
		scanf("%d",&ch);
	}while(ch);
	nsec=i;
	printf("\nSecond\tReceived\tSent\tDropped\tRemained\n");
	for(i=0;count||i<nsec;i++)
	{
		printf("%d\t",i+1);
		printf("%d\t",inp[i]);
		printf("\t%d\t",min((inp[i]+count),orate));
		if((x=inp[i]+count-orate)>0)
		{
			if(x>cap)
			{
				count=cap;
				drop=x-cap;
			}
			else
			{
				count=x;
				drop=0;
			}
		}
		else
		{
			drop=0;
			count=0;
		}
		printf("\t%d\t%d\n",drop,count);
	}
	return 0;
}
