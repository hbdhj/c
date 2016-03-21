#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
#include <string.h>

using namespace std;

bool checkProcName(int pid, char* toCheck)
{
    FILE *proc; 
    char pathName [30]; 
    char buffer [256]; 
    //char *buffPtr; 
    bool found= false; 
    /* Read the cmdline file for our process from /proc filesystem */ 
    sprintf(pathName, "/proc/%d/cmdline", pid); 
    cout<<"pathName is "<<pathName<<endl;
            
    if ((proc= fopen (pathName, "r")) != NULL) 
    {
        if (fgets (buffer, sizeof (buffer), proc) != NULL) 
        { 
            cout<<"buffer is "<<buffer<<endl;
            cout<<"strcmp("<<buffer<<", "<<toCheck<<") is "<<strcmp(buffer, toCheck)<<endl;
            
            if (strcmp(buffer, toCheck)>=0)
                 found= true; 
        } 
        fclose (proc); 
    }
    return found;
}

int main(int argc, char *argv[])
{
    if(argc!=3)
        return 1;
    int pid = atoi(argv[1]);
    if(checkProcName(pid,argv[2]))
        cout<<"Process id "<<pid<<" is "<<argv[2]<<endl;
    else
        cout<<"Process id "<<pid<<" is not "<<argv[2]<<endl;
    return 0;
}