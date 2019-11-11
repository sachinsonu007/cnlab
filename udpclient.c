#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>

int main()
{
	int clientsocket,portnum,nbytes;
	char buffer[1024];
	struct sockaddr_in serverAddr;
	socklen_t addr_size;
	clientsocket=socket(PF_INET,SOCK_DGRAM,0);
	serverAddr.sin_family=AF_INET;
	serverAddr.sin_port=htons(8893);
	serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
	memset(serverAddr.sin_zero,'\0',sizeof(serverAddr.sin_zero));
	addr_size=sizeof(serverAddr);

	while(1)
	{
		printf("Type a sentence to send to the server\n");
		fgets(buffer,1024,stdin);
		printf("You typed %s\n",buffer);
		nbytes=strlen(buffer)+1;
		sendto(clientsocket,buffer,nbytes,0,(struct sockaddr *)&serverAddr,addr_size);
		nbytes=recvfrom(clientsocket,buffer,1024,0,NULL,NULL);
		printf("Received From server %s \n",buffer);
	}
	return 0;
}
