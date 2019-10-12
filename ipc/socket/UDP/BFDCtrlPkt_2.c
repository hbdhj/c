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

int sendBFDCtrlPkt(BFDCtrlPktCfg &cfg, string server_ip="127.0.0.1", int port=3784) 
{
    // add code here
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