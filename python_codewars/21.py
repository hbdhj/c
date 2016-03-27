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
        sorted_list=sorted(str_n[i-1:])
        head_list = str_n[:i-2]
        for j in range(len(sorted_list)):
            if sorted_list[j] > str_n[i-2]:
                head_list+=sorted_list[j]
                sorted_list[j] = str_n[i-2]
                break
        ret= head_list + ''.join(sorted_list)
        if convert:
            return int(ret)
        else:
            return -1

assert(next_bigger(12)==21)
assert(next_bigger(513)==531)
assert(next_bigger(2017)==2071)
assert(next_bigger(414)==441)
assert(next_bigger(144)==414)
assert(next_bigger(9)==-1)
assert(next_bigger(111)==-1)
assert(next_bigger(531)==-1)
assert(next_bigger(1234567890)==1234567908)
assert(next_bigger(59884848459853)==59884848483559)
#59853 83559 93558