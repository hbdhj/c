#!/usr/bin/python

from socket import *

HOST = '10.87.128.121'
PORT = 21567
BUFSIZ =1024
ADDR = (HOST, PORT)

udpCliSock = socket (AF_INET, SOCK_DGRAM)

while True:
    data = raw_input('> ')
    if not data:
        break
    udpCliSock.sendto(data, ADDR)
    data, ADDR = udpCliSock.recvfrom(BUFSIZ)
    print data, ADDR
    if not data:
        break
udpCliSock.close()
