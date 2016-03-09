#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

//-lpthread

// #define PTHREAD_MUTEX_RECURSIVE 1

//pthread_mutex_t my_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
pthread_mutex_t my_mutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER;

void my_unlock_mutex(void)
{
    int retMutex;

    retMutex =  pthread_mutex_unlock(&my_mutex);
    if (retMutex) printf("fail - %s", strerror(retMutex));
}


void my_lock_mutex(void)
{
    int retMutex;

    retMutex = pthread_mutex_lock(&my_mutex);
    if (retMutex) printf("fail - %s", strerror(retMutex));
}

void my_init_mutex(void)
{
    int error;
    pthread_mutexattr_t mutex_attr;

    pthread_mutexattr_init(&mutex_attr);

#ifdef PTHREAD_MUTEX_RECURSIVE
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
#else
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_DEFAULT);
#endif

    error = pthread_mutex_init(&my_mutex, &mutex_attr);
    if (error) printf("fail - %s", strerror(error));
    pthread_mutexattr_destroy(&mutex_attr);
}

int g_iValue =0;

pthread_t thread_id1;
pthread_t thread_id2;

void *test1(void *t)
{
    my_lock_mutex();
    for(int i=0;i<10;i++)
    {
        g_iValue = 1;
        printf("value = %d thead = %d %s\n", g_iValue, pthread_self(), (pthread_self()==thread_id1)?"thread1":"error1");
        sleep(5);
    }
    my_unlock_mutex();
}

void *test2(void *t)
{
    my_lock_mutex();
    for(int i=0;i<10;i++)
    {
        g_iValue = 2;
        printf("value = %d thead = %d %s\n", g_iValue, pthread_self(), pthread_self()==thread_id2?"thread2":"error2");
        sleep(1);
    }
    my_unlock_mutex();
}


int main()
{
    int ret;
    my_init_mutex();

    ret = pthread_create(&thread_id1, NULL, test1, NULL);
    ret = pthread_create(&thread_id2, NULL, test2, NULL);

    //calling thread wait for thread_id1 terminlated
    pthread_join(thread_id1, NULL);
    //calling thread wait for thread_id1 terminlated
    pthread_join(thread_id2, NULL);

    printf("thread_id1 = %d, thread_id2= %d\n", thread_id1, thread_id2);

    return 0;
}
