# Merged String Checker

def is_merge(s, part1, part2):
    if len(part1)==0:
        if s==part2:
            return True
        else:
            return False
    if len(part2)==0:
        if s==part1:
            return True
        else:
            return False
    '''
    i=j=k=0;
    while i<len(s):
        print(i, s[i], j, part1[j], k, part2[k])
        if j<len(part1) and s[i]==part1[j]:
            j+=1;
            i+=1;
        elif k<len(part2) and s[i]==part2[k]:
            k+=1;
            i+=1;
        else:
            break;
    print(i, len(s), j, len(part1), k, len(part2))
    if i==len(s) and j==len(part1) and k==len(part2):
        return True
    else:
        return False
    '''
    if len(part2)+len(part1)!=len(s):
        return False
    ret = []
    for i in range(len(part1)):
        row = []
        for j in range(len(part2)):
            if s[i+j]==part1[i] or s[i+j]==part2[j]:
                row.append(0)
            else:
                row.append(1)
        ret.append(row)
    print(ret)
    if 0 in ret[-1]:
        return True
    else:
        return False
assert(is_merge('codewars', 'code', 'wars')==True)
assert(is_merge('codewars', 'cdw', 'oears')==True)
assert(is_merge('codewars', 'cod', 'wars')==False)
assert(is_merge('Bananas from Bahamas', 'Bahas', 'Bananas from am')==True)
assert(is_merge('Can we merge it? Yes, we can!', 'Can mer it?Y cn', 'wege es, wea!')==True)