#!/bin/bash

#ps -eo pid,ppid,vsz,rss,wchan,stat,time,args --cols 512 | head -1 > $2
while :
do
    sleep 1
    echo "===========================================================" 
    date 
    ps -eo pid,ppid,vsz,rss,wchan,stat,time,args --cols 512 | grep $1 
    free -l
    vmstat -sa
    pid_list=`ps -ef | grep $1 | grep -v grep | awk '{print $2}'`
    for pid in $pid_list
    do
        if [ -f /proc/$pid/oom_score]; then
            score=`cat /proc/$pid/oom_score`
            score_adj=`cat /proc/$pid/oom_score_adj`
            echo $pid,$score,$score_adj 
        fi
    done
done

