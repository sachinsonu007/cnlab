#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void receiver();
char frames[1024];

int main(int argc, char *argv[])
{
	int i,n,len;
	char buffer[1024],length[10];
	printf("Enter the number of frames\n");
	scanf("%d",&n);
	bzero(buffer,256);
	for(i=0;i<n;i++)
	{
		printf("Enter data to frame %d\n",i+1);
		scanf("%s",buffer);
		len=strlen(buffer);
		len++;
		printf("The length of the frame %d is %d \n",i+1,len);
		sprintf(length,"%d",len);
		strcat(frames,length);
		strcat(frames,buffer);
	}
	printf("Message sent from sender to receiver is \n");
	for(i=0;frames[i]!='\0';i++)
		printf("%c",frames[i]);
	receiver();
}

void receiver()
{
	int i,framelen,lpvar;
	char leninchar;
	while(frames[i]!='\0')
	{
		leninchar=frames[i];
		framelen=(int)leninchar-(int)'0';
		printf("\nThe frame length is %d\n Contents are \n",framelen);
		lpvar= i+framelen;
		while(i<lpvar)
			printf("%c",frames[i++]);
		printf("\n");
	}
}
