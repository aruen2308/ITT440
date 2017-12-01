#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int sock;
	struct sockaddr_in server;
	char msg[3000];
	
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock==-1){
	   printf("ERROR! COULD NOT CREATE SOCKET");
	}
	puts("SOCKET IS CREATED");

	server.sin_addr.s_addr=inet_addr("192.168.222.128");
	server.sin_family=AF_INET;
	server.sin_port=htons(1000);

	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0){
		perror("ERROR! FAILED TO CONNECT TO LOAD BALANCER");
		return 1;
	}

	printf("ENTER YOUR YOUR HERE");
	scanf("%s",msg);
	if(send(sock,msg,strlen(msg),0)<0){
	puts("ERROR! FAILED TO SEND");
	return 1;
	}
	close(sock);
	
return 0;
}
