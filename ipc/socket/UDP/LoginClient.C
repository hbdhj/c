#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <string>

using namespace std;

#define BUFLEN 512
#define NPACK 10
//#define SRV_IP "10.87.128.27"
//#define PORT 9930
/* diep(), #includes and #defines like in the server */

void diep(char *s)
{
    perror(s);
    exit(1);
}

int main(int argc, char *argv[])
{
    string server_ip="127.0.0.1";
	int port=8600;
	string account="admin";
	int opt;
	while ((opt = getopt(argc, argv, "i:p:u:")) != -1) {
		cout<<"opt = "<<(char)opt<<endl; 
        switch (opt) {
        case 'i':
            server_ip = optarg;
            break;
        case 'p':
            port = strtoul(optarg, NULL, 0);
            break;
        case 'u':
            account = optarg;
            break;

        default:
            fprintf(stderr, "Usage: %s [-i login_server_ip_addr] [-p login_server_port] [-u login_accout]...\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }
	cout<<"server_ip = "<<server_ip<<", port= "<<port<<", account = "<<account<<endl; 
	
	char buf[BUFLEN];
    sprintf(buf, "<LoginQuery xmlns=\"http://www.jdsu.com/loginserver\" schemaVersion=\"1.0\"><LoginQueryRequest><Username>%s</Username></LoginQueryRequest></LoginQuery>", account.c_str());
	printf("the buf is %s", buf); 
    
	/*struct sockaddr_in si_other;
    int s, i, slen=sizeof(si_other);
    
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
      diep("socket");

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(port);
    if (inet_aton(server_ip, &si_other.sin_addr)==0) {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }

    printf("Sending packet %d\n", i);
    sprintf(buf, "<LoginQuery xmlns=\"http://www.jdsu.com/loginserver\" schemaVersion=\"1.0\"><LoginQueryRequest><Username>%s</Username></LoginQueryRequest></LoginQuery>", account.c_str());
	printf("the buf is %d", buf); 
    if (sendto(s, buf, BUFLEN, 0, &si_other, slen)==-1)
        diep("sendto()");
    
    close(s);*/
    return 0;
}