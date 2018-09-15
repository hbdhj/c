#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <event.h>

// 定时事件回调函数 
void onTime(int sock, short event, void *arg) 
{ 
    printf("Hello,World!\n");

    struct timeval tv; 
    tv.tv_sec = 1; 
    tv.tv_usec = 0;

    // 重新添加定时事件（定时事件触发后默认自动删除） 
    event_add((struct event*)arg, &tv); 
} 
   
int main() 
{ 
    // 初始化 
    event_init(); 
   
    struct event ev_time; 
    // 设置定时事件 
    evtimer_set(&ev_time, onTime, &ev_time); 
   
    struct timeval tv; 
    tv.tv_sec = 1; 
    tv.tv_usec = 0; 
  
    // 添加定时事件 
    event_add(&ev_time, &tv); 
   
    // 事件循环 
    event_dispatch(); 
   
    return 0; 
}