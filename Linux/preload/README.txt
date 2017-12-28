compile
$ gcc -o verifypasswd verifypasswd.c
$ gcc -shared -o hack.so hack.c
test
$ ./verifypasswd asdf
reset LD_PRELOAD
$ export LD_PRELOAD="./hack.so"
run again
$ ./verifypasswd asdf