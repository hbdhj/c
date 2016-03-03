// fifo key words mkfifo open write read close
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define FIFO "/tmp/fifo"

int main(int argc,char *argv[])
{
    char buffer[80];
    int fd;
    unlink(FIFO);           //if FIFO exit,del FIFO file
    mkfifo(FIFO,0744);

    pid_t pid = fork();
	if(pid>0)
    {
        // father process
        char s[]="Hello!";
        fd = open(FIFO, O_WRONLY);
        printf("this is father write data is %s\n", s);
		printf("father's pid is %d\n", getpid());
        write(fd, s, sizeof(s));
        close(fd);
		exit(EXIT_SUCCESS);
    }
	else if(pid==0)
    {
        // child process
        sleep(2);
		fd = open(FIFO, O_RDONLY);
        read(fd, buffer, 80);
	    printf("this is child read data is:%s\n", buffer);
        close(fd);
		printf("child's pid is %d\n", getpid());
		exit(EXIT_SUCCESS);
    }
	else
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
}
