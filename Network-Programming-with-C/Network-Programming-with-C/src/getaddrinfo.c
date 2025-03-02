/*
** Sample code for a client application who want to connect to a particular server,
** say "www.example.net" on port 3490.
** This code does not connect but it sets up the structures we'll use later.
*/
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
	int status;
	struct addrinfo hints;
	struct addrinfo *servinfo;			//wil point to the results
	
	memset(&hints, 0, sizeof hints);	// make sure the struct is empty
	hints.ai_family = AF_UNSPEC;		// don't care if IPv4 or IPv6
	hints.ai_socktype = SOCK_STREAM;	// TCP stream sockets
	
	status = getaddrinfo("www.example.net", "3490", &hints, &servinfo);

	printf("%d\n", status);
	printf("%d\n%d\n%d\n%d\n",  servinfo->ai_flags,
								servinfo->ai_family,
								servinfo->ai_socktype,
								servinfo->ai_protocol);
}
