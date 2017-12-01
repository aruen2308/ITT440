#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(){
	int socket_desc,client_sock,c,read_size;
	struct sockaddr_in server,client;
	char client_msg[3000];

	socket_desc=socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc==-1){
		printf("CANNOT CREATE SOCKET");
	}
	
	puts("SOCKET CREATED");
	
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(4000);
	
	if(bind(socket_desc,(struct sockaddr *)&server,sizeof(server))<0){
	perror("FAIL TO BIND THE SOCKET TO SERVER");
	return 1;
	}
	
	puts("BIND DONE");

	listen(socket_desc,3);

	puts("WAITING FOR INCOMING CONNECTION");
	c=sizeof(struct sockaddr_in);

	client_sock=accept(socket_desc,(struct sockaddr *)&client,(socklen_t *)&c);
	if(client_sock<0){
	perror("ACCEPT FAILED");
	return 1;
	}
	puts("CONNECTION ACCEPTED");

	read_size=recv(client_sock,client_msg,3000,0);

	printf("%s",client_msg);
	
	
}
