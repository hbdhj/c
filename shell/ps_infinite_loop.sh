#!/bin/bash

ps -eo pid,ppid,vsz,rss,wchan,stat,time,args --cols 512 | head -1 > $2
while :
do
	sleep 1
	ps -eo pid,ppid,vsz,rss,wchan,stat,time,args --cols 512 | grep $1 >> $2
done