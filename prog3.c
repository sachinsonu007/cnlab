#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n strlen(g)
char t[128],cs[128],g[]="100000111";
int a,c,e;
void xor()
{
	for(c=0;c<n;c++)
		cs[c]=((cs[c]==g[c])?'0':'1');
}

void crc()
{
	for(e=0;e<n;e++)
		cs[e]=t[e];
	do
	{
		if(cs[0]=='1')
			xor();
		for(c=0;c<n-1;c++)
			cs[c]=cs[c+1];
		cs[c]=t[e++];
	}while(e<=a+n-1);
}

void main()
{
	printf("Enter poly\n");
	scanf("%s",t);
	printf("The generating polynomial is %s\n",g);
	a=strlen(t);
	for(e=a;e<a+n-1;e++)
		t[e]='0';
	printf("MOdified t[u] is %s\n",t);
	crc();
	printf("checksum is %s\n",cs);
	for(e=a;e<a+n-1;e++)
		t[e]=cs[e-a];
	printf("Final codeword is %s\n",t);
	printf("Test error detecion 0(YES),1(NO)?\n");
	scanf("%d",&e);
	if(e==0)
	{
		printf("Enter the position where error is to be inserted\n");
		scanf("%d",&e);
		t[e]=((t[e]=='0')?'1':'0');
		printf("Erroneous data is %s\n",t);
	}
	crc();
	for(e=0;((e<n-1)&&(cs[e]!='1'));e++)
	{
		if(e<n-1)
			printf("Error detected\n");
		else
			printf("Error not detected\n");
	}
}
