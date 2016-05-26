#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <pthread.h>

//-lpthread


int main()
{
    pthread_mutex_t my_mutex = PTHREAD_MUTEX_INITIALIZER;
    printf("create mutex success\n");

    pthread_mutexattr_t mutex_attr;
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_DEFAULT);
    printf("create mutex attr success\n");

    int error = pthread_mutex_init(&my_mutex, &mutex_attr);
    if (error)
        printf("init mutex fail - %s\n", strerror(error));
    printf("init mutex success\n");

    error = pthread_mutex_lock(&my_mutex);
    if (error)
        printf("lock first time fail - %s\n", strerror(error));
    printf("lock mutex first time success\n");
    error = pthread_mutex_lock(&my_mutex);
    if (error)
        printf("lock second time fail - %s", strerror(error));
    printf("lock mutex second time success");
    error =  pthread_mutex_unlock(&my_mutex);
    if (error)
        printf("unlock first time fail - %s", strerror(error));
    printf("unlock mutex first time success");
    error =  pthread_mutex_unlock(&my_mutex);
    if (error)
        printf("unlock second time fail - %s\n", strerror(error));
    printf("unlock mutex second time success\n");

    pthread_mutexattr_destroy(&mutex_attr);
    return 0;
}
