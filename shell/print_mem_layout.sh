#!/bin/bash

while :
do
    sleep 1
    echo "==========================================================="
    date
    pid_list=`ps -ef | grep $1 | grep -v grep | awk '{print $2}'`
    for pid in $pid_list; do
        if [ -f /proc/$pid/maps ]; then
            cat /proc/$pid/maps
        fi
    done
done
