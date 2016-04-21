============================
------on same machine------
- Unix
1. noname pipe
2. named pipe - fifo
3. signal

- System V
1. semaphore
2. msg queue
3. shared memory

----on different machine----
1. rpc
2. socket

============================
------data exchange------
on same machine
1. unamed pipe
2. named pipe - fifo
3. msg queue
4. shared memory

on different machine
1. rpc
2. socket

------a/synchronization------
1. semaphore
2. signal

======== key words ===========
rpc = rpcgen
fifo = mkfifo open write read close
msg queue = ftok msgget msgctl msgsnd msgrcv
pipe = pipe read write close
semaphore = ftok semget semop
shared memory = ftok shmget shmat shmdt
signal = signal
socket client = socket connect send recv close
socket server = socket bind listen accept send recv close
socket server select = socket bind listen select accept sock_gets sock_puts close
socket server epoll = socket epoll_ctl bind listen epoll_wait accept read write close
