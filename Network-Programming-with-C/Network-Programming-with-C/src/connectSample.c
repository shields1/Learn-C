#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

int main(int argc, char *argv[]) {

	struct addrinfo hints, *res;
	int sockfd, status;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	
	if ((status = getaddrinfo("www.example.com", "3490", &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 1;
	}

	if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
		fprintf(stderr, "socket: %s\n", gai_strerror(sockfd));
		return 2;
	}

	if ((status = connect(sockfd, res->ai_addr, res->ai_addrlen)) != 0) {
	fprintf(stderr, "connect: %s\n", gai_strerror(status));
		return 3;
	}
}
