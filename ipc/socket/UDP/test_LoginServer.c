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

#define BUFLEN 256
#define NPACK 10

void diep(char *s)
{
    perror(s);
    exit(1);
}

//sprintf(buf, "<LoginQuery xmlns=\"http://www.jdsu.com/loginserver\" schemaVersion=\"1.0\"><LoginQueryResponse><Username>admin</Username><ResponseCode>0</Response><Server>%s</Server></LoginQueryResponse></LoginQuery>", v_l_field_ca);
string xmlParserUsername(string input)
{
    size_t findStartTag=input.find("Username");
    size_t findEndTag=input.find("/Username");
    cout<<"findStartTag = "<<findStartTag<<", findEndTag = "<<findEndTag<<endl;
    return input.substr(findStartTag+9, findEndTag-findStartTag-10);
}

string xmlParserServer(string input)
{
    size_t findStartTag=input.find("Server");
    size_t findEndTag=input.find("/Server");
    cout<<"findStartTag = "<<findStartTag<<", findEndTag = "<<findEndTag<<endl;
    return input.substr(findStartTag+7, findEndTag-findStartTag-8);
}
                    
int main(int argc, char *argv[])
{
    string server_ip="127.0.0.1";
    int serv_port=8600;
    string account="admin";
    int opt;
    while ((opt = getopt(argc, argv, "i:p:u:")) != -1) 
    {
        //cout<<"opt = "<<(char)opt<<endl; 
        switch (opt) {
        case 'i':
            server_ip = optarg;
            break;
        case 'p':
            serv_port = strtoul(optarg, NULL, 0);
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
    //cout<<"server_ip = "<<server_ip<<", port= "<<port<<", account = "<<account<<endl; 
    
    
    struct sockaddr_in si_me, si_other;
#ifdef LINUX
    socklen_t slen = sizeof(socklen_t);
#else
    unsigned int slen = sizeof(socklen_t);
#endif
    int socket_id, i;
    
    if ((socket_id=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        diep("create socket failed, the reason is ");
    
    memset((char *) &si_me, 0, sizeof(si_me));
    memset((char *) &si_other, 0, sizeof(si_other));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(0);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
#ifdef LINUX
    if (bind(socket_id, (struct sockaddr *)&si_me, sizeof(si_me))==-1)
#else
    if (bind(socket_id, &si_me, sizeof(si_me))==-1)
#endif
        diep("socket binded failed, the reason is ");
    else
        cout<<"bind socket "<<socket_id<<" success"<<endl;
        
    //struct sockaddr real_port;
#ifdef LINUX
    socklen_t real_port_len = sizeof(socklen_t);
#else
    int real_port_len = sizeof(int);
#endif
    //struct sockaddr_in *real_si_me=(sockaddr_in *)&real_port;
    struct sockaddr_in real_si_me;
    if (getsockname(socket_id, (struct sockaddr*)&real_si_me, &real_port_len)==-1)
    {
        cout<<"socket_id = "<<socket_id<<", real_port_len = "<<real_port_len<<endl;
        diep("sgetsockname() failed, the reason is ");
    }
    
    cout<<"now we are listen on port "<<ntohs(real_si_me.sin_port)<<endl;
    
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(serv_port);
    if (inet_aton(server_ip.c_str(), &si_other.sin_addr)==-1) 
        diep("inet_aton() failed, the reason is : ");
    char buf[BUFLEN];
    sprintf(buf, "<LoginQuery xmlns=\"http://www.jdsu.com/loginserver\" schemaVersion=\"1.0\"><LoginQueryRequest><Username>%s</Username></LoginQueryRequest></LoginQuery>", account.c_str());
    printf("The xml msg to sent is %s\n", buf); 
    
#ifdef LINUX
    if (sendto(socket_id, buf, BUFLEN, 0, (struct sockaddr *)&si_other, real_port_len)==-1)
#else
    if (sendto(socket_id, buf, BUFLEN, 0, &si_other, real_port_len)==-1)
#endif
    {
        cout<<"socket_id = "<<socket_id<<", real_port_len = "<<real_port_len<<endl;
        cout<<"si_other.sin_family = "<<si_other.sin_family<<endl;
        cout<<"si_other.sin_port = "<<ntohs(si_other.sin_port)<<endl;
        diep("sendto() failed, the reason is : ");
    }
    else
    {
        cout<<"Send msg to ip "<<inet_ntoa(si_other.sin_addr)<<" port "<<ntohs(si_other.sin_port)<<" success."<<endl;
    }
    int getResponse = 0;
    while(0==getResponse)
    {
        char rec_buf[BUFLEN];
        slen = sizeof(si_other);
        printf("Try to receive msg from socket %d %s:%d slen = %d BUFLEN = %d\n", socket_id, inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), slen, BUFLEN);
#ifdef LINUX
        if (recvfrom(socket_id, rec_buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)==-1)
#else
        if (recvfrom(socket_id, rec_buf, BUFLEN, 0, &si_other, (int*)&slen)==-1)
#endif
        {
            printf("Received msg from socket %d %s:%d slen = %d BUFLEN = %d failed\n", socket_id, inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), slen, BUFLEN);
            diep("recvfrom()");
        }
        else
        {
            printf("Received msg from %s:%d\nMsg details: %s\n", inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), rec_buf);
            cout<<"Get the login server IP "<<xmlParserServer(rec_buf)<<" for account "<<xmlParserUsername(rec_buf)<<endl;
            getResponse = 1;
        }
    }
    close(socket_id);
    return 0;
}
