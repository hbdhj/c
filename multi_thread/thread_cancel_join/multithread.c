// 测试代码
#define PTHREAD_THREADS_MAX 1024

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *fun(void *arg)
{
    int i,j=5;
    unsigned char buffer[200];
    while (1)
    {
        for ( i=1;i<100;i++ )
        {
            buffer[i] = j * (j-1) * (j-2) * (j-3) * (j-4);
        }
        sleep(1);
    }
}

int main(void)
{
    pthread_t t[PTHREAD_THREADS_MAX];
    int i, j;
    int ret;

    //cout << "System's max count of threads is : " << PTHREAD_THREADS_MAX << endl;
    //max_thread_proc(256);
    pthread_attr_t threadAttr;
    pthread_attr_init(&threadAttr);
    pthread_attr_setstacksize(&threadAttr, 256*256);
    for ( i=0;i<PTHREAD_THREADS_MAX;i++ )
    {
        cout << "Create thread " << i <<", ";
        ret = pthread_create(&t[i], &threadAttr, fun, NULL);

        // 修改部分 ******************
        cout << "result: " << ret << endl;
        if ( ret ) 
        {
            cout<<errno<<", "<<strerror(errno)<<endl;
            break;
        }
        //**************************
    }

    for ( j=0;j<=i;j++ )
    {
        pthread_cancel(t[j]);
    }
    pthread_attr_destroy(&threadAttr);
    return 0;
}

