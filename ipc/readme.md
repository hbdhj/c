[TOC]

# Scope
## on same machine
### Unix
1. noname pipe
2. named pipe - fifo
3. signal

### System V
1. semaphore
2. msg queue
3. shared memory

## on different machine
1. rpc
2. socket

# Usage
##  data exchange
### on same machine
1. unamed pipe
2. named pipe - fifo
3. msg queue
4. shared memory

### on different machine
1. rpc
2. socket

## a/synchronization
1. semaphore
2. signal

# key words
1. rpc = rpcgen
2. fifo = mkfifo open write read close
3. msg queue = ftok msgget msgctl msgsnd msgrcv
4. pipe = pipe read write close
5. semaphore = ftok semget semop
6. shared memory = ftok shmget shmat shmdt
7. signal = signal
8. socket client = socket connect send recv close
9. socket server = socket bind listen accept send recv close
10. socket server select = socket bind listen select accept sock_gets sock_puts close
11. socket server epoll = socket epoll_ctl bind listen epoll_wait accept read write close
