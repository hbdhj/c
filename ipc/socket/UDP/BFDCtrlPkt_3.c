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

struct BFDCtrlPktCfg {
    uint32_t myDis;
    uint32_t yourDis;
    uint32_t minTxInterval;
    uint32_t minRxInterval;
    uint32_t minEchoRxInterval;
};

int sendBFDCtrlPkt(BFDCtrlPktCfg &cfg, string server_ip="127.0.0.1",    int port=3784) 
{
    struct sockaddr_in si_other;
    int s, slen=sizeof(si_other);
    
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1) {
        fprintf(stderr, "socket() failed\n");
        return 1;
    }

    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(port);
    if (inet_aton(server_ip.c_str(), &si_other.sin_addr)==0) {
        fprintf(stderr, "inet_aton() failed\n");
        return 1;
    }

    char buf[BUFLEN];
    
    // add code here
    
    if (sendto(s, buf, BUFLEN, 0, (struct sockaddr *)&si_other, slen)==-1) {
        fprintf(stderr, "sendto() failed\n");
        return 1;
    }
    
    close(s);
    return 0;
};

int sendBFDCtrlPktUT()
{
    BFDCtrlPktCfg cfg;
    cfg.myDis = 123;
    cfg.yourDis = 456;
    cfg.minTxInterval = 1000;
    cfg.minRxInterval = 1000;
    cfg.minEchoRxInterval = 50;
    
    sendBFDCtrlPkt(cfg);
    return 0;
}

int main(int argc, char *argv[])
{
    sendBFDCtrlPktUT();
    
    return 0;
}