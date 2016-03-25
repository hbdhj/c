# Roman Numerals Encoder

def solution(n):
    # TODO convert int to roman string
    chr_lst = [['I','V'],['X', 'L'],['C','D'],['M']]
    ret =""
    str_n = str(n)
    n = len(str_n)
    for i in range(n):
        c = str_n[n-i-1]
        c_i = int(c)
        if c_i<4:
            for j in range(c_i):
                ret=chr_lst[i][0]+ret
        elif c_i==4:
           ret=chr_lst[i][0]+chr_lst[i][1]+ret
        elif c_i==5:
            ret=chr_lst[i][1]+ret
        elif c_i==9:
            ret=chr_lst[i][0]+chr_lst[i+1][0]+ret
        elif c_i<9:
            for j in range(5, c_i):
                ret=chr_lst[i][0]+ret
            ret=chr_lst[i][1]+ret
    #print(ret)
    return ret

assert(solution(1)=='I')
assert(solution(4)=='IV')
assert(solution(5)=='V')
assert(solution(6)=='VI')
assert(solution(10)=='X')
assert(solution(50)=='L')
assert(solution(100)=='C')
assert(solution(500)=='D')
assert(solution(1000)=='M')
assert(solution(2008)=='MMVIII')