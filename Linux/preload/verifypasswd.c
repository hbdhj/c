/* 文件名：verifypasswd.c */
/* 这是一段判断用户口令的程序，其中使用到了标准C函数strcmp */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char passwd[] = "password";
    if (argc < 2) {
        printf("usage: %s <password>/n", argv[0]);
        exit(1);
    }

    if (!strcmp(passwd, argv[1])) {
        printf("Correct Password!/n");
        exit(2);
    }

    printf("Invalid Password!/n");
    exit(0);
}
