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
    // add code here
};

int sendBFDCtrlPkt(BFDCtrlPktCfg &cfg, string server_ip="127.0.0.1", int port=3784) 
{
    // add code here
    
    return 0;
};

int sendBFDCtrlPktUT()
{
    BFDCtrlPktCfg cfg;
    // add code here
    
    sendBFDCtrlPkt(cfg);
    return 0;
}

int main(int argc, char *argv[])
{
    sendBFDCtrlPktUT();
    
    return 0;
}