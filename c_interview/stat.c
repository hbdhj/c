#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() 
{
    struct stat buf;
    dev_t st_dev;
    ino_t st_ino;
    stat("/etc/hosts", &buf);
    printf("/etc/hosts file size = %d\n", buf.st_size);
    printf("/etc/hosts dev = %d\n", buf.st_dev);
    printf("/etc/hosts inode = %d\n", buf.st_ino);
    return 0;
}