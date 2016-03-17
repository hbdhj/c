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

string xmlParser(string input)
{
    size_t findStartTag=input.find("Username");
    size_t findEndTag=input.find("/Username");
    cout<<"findStartTag = "<<findStartTag<<", findEndTag = "<<findEndTag<<endl;
    return input.substr(findStartTag+9, findEndTag-findStartTag-10);
}

int main(int argc, char *argv[])
{
    cout<<xmlParser("<LoginQuery xmlns=\"http://www.jdsu.com/loginserver\" schemaVersion=\"1.0\"><LoginQueryRequest><Username>admin</Username></LoginQueryRequest></LoginQuery>")<<endl;
    return 0;
}
