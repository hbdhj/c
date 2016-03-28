#include <iostream>
#include <pthread.h>
#include "thread_tasks.h"

using namespace std;

int Answer = 10;
int flag1 = 0;
int flag2 = 0;

int main(int argc, char *argv[])
{

    pthread_t ThreadA, ThreadB, ThreadC;

    cout << "Answer = " << Answer << endl;
    pthread_create( &ThreadA,NULL,task1,NULL);
    pthread_create( &ThreadB,NULL,task2,NULL);
    pthread_create( &ThreadC,NULL,task3,NULL);
    pthread_join(ThreadA,NULL);
    pthread_join(ThreadB,NULL);
    pthread_join(ThreadC,NULL);

    cout << "Answer = " << Answer << endl;

    return(0);
 }
