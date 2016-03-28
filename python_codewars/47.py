# Playing with digits

import math

def dig_pow(n, p):
    ret = 0
    for i in range(len(str(n)),0, -1):
        #print(i+p-1,str(n)[i-1])
        ret+=math.pow(int(str(n)[i-1]), i+p-1)
    if ret%n==0:
        return ret/n
    return -1

assert(dig_pow(89, 1)==1)
assert(dig_pow(92, 1)==-1)
assert(dig_pow(46288, 3)==51)