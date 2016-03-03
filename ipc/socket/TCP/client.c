// socket client key words socket connect send recv close
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUFFSIZE 32

bool running = false;
int sock;
void Die(char *mess) { perror(mess); _exit(1); }
void  SIGINT_handler(int){printf("SIGINT received\n");running = false;  printf("closing ...\n");close(sock);_exit(0);};

int main(int argc, char *argv[]) {
    struct sockaddr_in echoserver;
    char buffer[BUFFSIZE];
    unsigned int echolen;
    int received = 0;

    if (argc != 3) {
        fprintf(stderr, "USAGE: TCPecho <server_ip> <word> <port>\n");
        _exit(1);
    }

    /* install signal handler for SIGINT */
    if (signal(SIGINT, SIGINT_handler) == SIG_ERR) {
         printf("SIGINT install error\n");
         _exit(1);
    }

    /* Create the TCP socket */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        Die("Failed to create socket");
    }

    /* Construct the server sockaddr_in structure */
    memset(&echoserver, 0, sizeof(echoserver));       /* Clear struct */
    echoserver.sin_family = AF_INET;                  /* Internet/IP */
    echoserver.sin_addr.s_addr = inet_addr(argv[1]);  /* IP address */
    echoserver.sin_port = htons(atoi(argv[2]));       /* server port */

    /* Establish connection */
    if (connect(sock,
                (struct sockaddr *) &echoserver,
                sizeof(echoserver)) < 0) {
                    Die("Failed to connect with server");
                }
    running = true;
    while(running)
    {
        /* get some input */
        char msg [BUFFSIZE];
        int i;

        // reset the msg
        memset(msg, '\0', sizeof(msg));

        // get input msg
        printf ("Enter your msg: \n");
        scanf ("%31s",msg);
        printf ("We are going to send msg: %s\n", msg);

        /* Send the word to the server */
        echolen = strlen(msg);
        if (send(sock, msg, echolen, 0) != echolen) {
            Die("Mismatch in number of sent bytes");
        }

        /* Receive the word back from the server */
        while (received < echolen) {
            int bytes = 0;
            if ((bytes = recv(sock, buffer, BUFFSIZE-1, 0)) < 1) {
                Die("Failed to receive bytes from server");
            }
            received += bytes;
            buffer[bytes] = '\0';        /* Assure null terminated string */
            fprintf(stdout, "Received '%s' from server\n", buffer);
        }
        //fprintf(stdout, "\n");
    }
    fprintf(stdout, "closing ...\n");
    close(sock);
    _exit(0);
}
