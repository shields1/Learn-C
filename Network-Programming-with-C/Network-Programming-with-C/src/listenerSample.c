#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define MYPORT "3490"
#define BACKLOG 10

int main(void) {
	
	struct sockaddr_storage clients_addr;
	socklen_t addr_size;
	struct addrinfo hints, *res;
	int sockfd, new_fd, status;

	memset(&hints, 0, sizeof hints);
	hints.ai_family = AF_UNSPEC;	// use IPv4 or IPv6, I don't care..
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_flags = AI_PASSIVE;	// fill in my IP for me
	
	
	if ((status = getaddrinfo(NULL, MYPORT, &hints, &res)) != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
		return 1;
	}

	if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) == -1) {
		fprintf(stderr, "socket: %s\n", gai_strerror(errno));
		return 2;
	}

	if (bind(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
		fprintf(stderr, "bind: %s\n", gai_strerror(status));
		return 3;
	}

	if (listen(sockfd, BACKLOG) == -1) {
		fprintf(stderr, "listen: %s\n", gai_strerror(status));
		return 4;
	}

	addr_size = sizeof clients_addr;
	new_fd = accept(sockfd, (struct sockaddr *)&clients_addr, &addr_size);
	if (new_fd == -1) {
		fprintf(stderr, "accept: %s\n", gai_strerror(errno));
		  return 5;
	}
}
