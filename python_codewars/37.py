# snail

def snail(array):
    if len(array)==0:
        return []
    elif len(array)==1:
        ret = []
        ret+=array[0]
        return ret
    elif len(array[0])==1:
        ret = []
        for i in range(0, len(array)):
            ret+=array[i]
        return ret
    elif len(array)==2 and len(array[0])==2:
        ret = []
        ret.append(array[0][0])
        ret.append(array[0][1])
        ret.append(array[1][1])
        ret.append(array[1][0])
        return ret
    else:
        ret = array[0]
        for i in range(1, len(array)-1):
            #print(i, len(array[i])-1, len(array))
            ret.append(array[i][len(array[i])-1])
        ret += array[-1][::-1]
        for i in range(len(array)-2, 0, -1):
            ret.append(array[i][0])
        #print(ret)
        left = []
        for i in range(1, len(array)-1):
            left.append(array[i][1:-1])
        #print(left)
        ret+= snail(left)
        #print(ret)
        return ret


array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
expected = [1,2,3,6,9,8,7,4,5]
assert(snail(array)==expected)


array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
expected = [1,2,3,4,5,6,7,8,9]
assert(snail(array)==expected)


array = [[1,2,3,4],
         [12,13,14,5],
         [11,16,15,6],
         [10,9,8,7]]
expected = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]
assert(snail(array)==expected)