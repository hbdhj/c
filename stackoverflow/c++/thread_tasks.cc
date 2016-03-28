#include <iostream>
#include <pthread.h>
#include "thread_tasks.h"

using namespace std;

extern int Answer;
pthread_mutex_t Mutex;
extern int flag1;
extern int flag2;

void *task1(void *X)
{
    pthread_mutex_lock( &Mutex);
    Answer = Answer * 32; //critical section
    flag1=1;
    pthread_mutex_unlock( & Mutex);
    cout << "\nthread A Answer = " << Answer << endl;
    cout << "\nthread 1 executed successfully";
}

void *task2(void *X)
{
    if(flag1==1)
    {
        pthread_mutex_lock( &Mutex);
        Answer = Answer/2;
        flag2=1;
        pthread_mutex_unlock( & Mutex);
        cout<<"\nthread 2 executed successfully";
    }
}

void *task3(void *X)
{
    if (flag2==1)
    {
        pthread_mutex_lock( &Mutex);
        Answer = Answer+5;
        pthread_mutex_unlock( & Mutex);
        cout<<"\nthread 3 executed successfully";
    }
}
