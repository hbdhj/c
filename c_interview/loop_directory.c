#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>  
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

void listDir(char *path)
{  
    DIR              *pDir ;
    struct dirent    *ent  ;
    int               i=0  ;
    char              childpath[512];  

    pDir=opendir(path);
    memset(childpath,0,sizeof(childpath));

    while((ent=readdir(pDir))!=NULL)  
    {
        if(ent->d_type & DT_DIR)  
        {
            if(strcmp(ent->d_name,".")==0 || strcmp(ent->d_name,"..")==0)  
                continue;

            sprintf(childpath,"%s/%s",path,ent->d_name);  
            printf("path:%s/n",childpath);  

            listDir(childpath);
        }  
        else
        {
            cout<<ent->d_name<<endl;
        }
    }  
}  
  
int main(int argc,char *argv[])
{  
    listDir(argv[1]);  
    return 0;
}