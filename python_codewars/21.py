# Next bigger number with the same digits

def next_bigger(n):
    str_n = str(n)
    if len(str_n)<=1:
        return -1
    else:
        convert = False
        for i in range(len(str_n), 1, -1):
            if str_n[i-1]>str_n[i-2] and convert == False:
                convert = True
                break
        ret_list = sorted(str_n[i:]+str_n[i-2])
        ret= ''.join(ret_list)
        ret = str_n[:i-2] + str_n[i-1] + ret
        print(ret)
        if convert:
            return int(ret)
        else:
            return -1

#assert(next_bigger(12)==21)
#assert(next_bigger(513)==531)
#assert(next_bigger(2017)==2071)
#assert(next_bigger(414)==441)
#assert(next_bigger(144)==414)
#assert(next_bigger(9)==-1)
#assert(next_bigger(111)==-1)
#assert(next_bigger(531)==-1)
#assert(next_bigger(1234567890)==1234567908)
assert(next_bigger(59884848493558)==59884848483559)