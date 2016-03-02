/***************************************************************************/
/*                                                                         */
/*       Copyright JDS Uniphere U.S.A, Ltd. 1995-2012.                     */
/*       All Rights Reserved                                               */
/*                                                                         */
/***************************************************************************/
/*                                                                         */
/*  System Name   : Access7                                                */
/*  File Type     : Function Source                                        */
/*  Segment Name  : Eternal App                                            */
/*  Task Name     : Login Server for VzW web access security               */
/*  Module Name   : Login Server Control                                   */
/*  Identity      : u3500.c                                                */
/*  Author        : Deng Haijun, JDSU                                      */
/*  Date Written  : 12-04-2012                                             */
/*                                                                         */
/***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <pthread.h>
#include <sys/types.h>
#include <pwd.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFLEN 512

using namespace std;

int running;
string server_ip="0.0.0.0";
int udp_socket;
#ifdef LINUX
socklen_t slen;
#else
int slen;
#endif
int loginServerUdpPort=8600;
struct sockaddr_in si_me, si_other;

void diep(char *s)
{
    perror(s);
    exit(1);
}

void u35_sig_handler(int signal)
{
    running = 0;
}

string xmlParser(string input)
{
    size_t findStartTag=input.find("Username");
    size_t findEndTag=input.find("/Username");
    cout<<"findStartTag = "<<findStartTag<<", findEndTag = "<<findEndTag<<endl;
    return input.substr(findStartTag+9, findEndTag-findStartTag-10);
}

void sendQueryServerMsg(string userName)
{
    char buf[BUFLEN];
    sprintf(buf, "<LoginQuery xmlns=\"http://www.jdsu.com/loginserver\" schemaVersion=\"1.0\"><LoginQueryResponse><Username>%s</Username><ResponseCode>0</Response><Server>%s</Server></LoginQueryResponse></LoginQuery>", userName.c_str(), "1.2.3.4");
#ifdef LINUX
    if (sendto(udp_socket, buf, BUFLEN, 0, (struct sockaddr *)&si_other, slen)==-1)
#else
    if (sendto(udp_socket, buf, BUFLEN, 0, &si_other, slen)==-1)
#endif

    {
        cout<<"Sent msg to ARD failed"<<endl;
    }
    else
    {
        printf("Sent msg to %s:%d\nMsg details: %s\n\n", 
                inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
    }
}

static void *thread_start(void *arg)
{
    cout<<"start thread"<<endl;
    slen=sizeof(si_other);
    char buf[BUFLEN];
    
    if ((udp_socket=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        diep("socket create failed");
    else
        cout<<"socket "<<udp_socket<<" created"<<endl;
    memset((char *) &si_me, 0, sizeof(si_me));
    memset((char *) &si_other, 0, sizeof(si_other));
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(loginServerUdpPort);
    if (server_ip.compare("0.0.0.0") == 0)
        si_me.sin_addr.s_addr = htonl(INADDR_ANY);
    else
        inet_aton(server_ip.c_str(), &(si_me.sin_addr));
#ifdef LINUX
    if (bind(udp_socket, (struct sockaddr *)&si_me, sizeof(si_me))==-1)
#else
    if (bind(udp_socket, &si_me, sizeof(si_me))==-1)
#endif
        diep("socket binded");
    else
    {
        cout<<"bind socket "<<udp_socket<<" on ip "<<inet_ntoa(si_me.sin_addr)<<" port "<<ntohs(si_me.sin_port)<<" success"<<endl;
    }    
    while(1 == running)
    {
        cout<<"try to receive data from ip "<<inet_ntoa(si_me.sin_addr)<<" port "<<ntohs(si_me.sin_port)<<endl;
#ifdef LINUX
        if (recvfrom(udp_socket, buf, BUFLEN, 0, (struct sockaddr *)&si_other, &slen)==-1)
#else
        if (recvfrom(udp_socket, buf, BUFLEN, 0, &si_other, &slen)==-1)
#endif        
            diep("recvfrom");
        else
        {
            printf("Received msg from %s:%d\nMsg details: %s\n", 
                inet_ntoa(si_other.sin_addr), ntohs(si_other.sin_port), buf);
            string accoutName = xmlParser(buf);
            cout<<"Now try to get login server for account "<<accoutName<<endl;
            sendQueryServerMsg(accoutName);
        }
    }
    cout<<"thread_start exit"<<endl;
}

int main(int argc, char** argv)
{
    int opt;
    while ((opt = getopt(argc, argv, "i:p:")) != -1) 
    {
        //cout<<"opt = "<<(char)opt<<endl; 
        switch (opt) {
        case 'i':
            server_ip = optarg;
            break;
        case 'p':
            loginServerUdpPort = strtoul(optarg, NULL, 0);
            break;
        default:
            fprintf(stderr, "Usage: %s [-i login_server_ip_addr] [-p login_server_port] [-u login_accout]...\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }
    
    signal(SIGINT, u35_sig_handler);
    // Start UDP listen thread
    pthread_t tUdpThread;
    pthread_attr_t attr;
    int ret = pthread_attr_init(&attr);
    running = 1;
    ret = pthread_create(&tUdpThread, &attr, &thread_start, NULL);
    // Now run to read U35 queue
    
    while(1 == running)
    {
        sleep(20);
    }
    ret = pthread_attr_destroy(&attr);
    
    return 0;
}
