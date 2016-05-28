#include <stdio.h>
#include <pthread.h>

void *threadMainLoop(void *arg){
    char **arguments = (char**)arg;
    printf("args[0] =%s\n", arguments[0]);
    printf("args[1] =%s\n", arguments[1]);
    return NULL;
}

int main(int argc, char *argv[]){
    printf("Start of program execution\n");
    pthread_t outboundThread;
    int rc = pthread_create(&outboundThread, NULL, threadMainLoop, (void *) argv);
    printf("Thread create return %i and thread id is %d\n", rc, outboundThread);
    if(rc != 0){
        printf("Thread creation failed\n");
        exit(1);
    }
    pthread_join(outboundThread, NULL);
    return 0;
}
