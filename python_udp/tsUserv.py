#!/usr/bin/python

from socket import *
from time import ctime

HOST = '10.87.128.121'
PORT = 21567
BUFSIZ =1024
ADDR = (HOST, PORT)

udpServSock = socket (AF_INET, SOCK_DGRAM)
udpServSock.bind(ADDR)

while True:
    print 'wait for message...'
    data, addr = udpServSock.recvfrom(BUFSIZ)
    print data, addr
    udpServSock.sendto('[%s] %s' %(ctime(), data), addr)
    print '...received from and returned to:', addr

udpCliSock.close()
