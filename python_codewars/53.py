#

def sum_pairs(ints, s):
    pos_dict = {}
    pos_min = len(ints)
    ret = None
    for pos in range(len(ints)):
        n = ints[pos]
        #print(pos, n, pos_dict)
        if n not in pos_dict.keys():
            pos_dict[n] = pos
        else:
            if pos < pos_dict[n]:
                pos_dict[n] = pos
        if (s - n) in pos_dict.keys():
            tmp_min = max(pos_dict[n], pos_dict[s-n])
            if tmp_min < pos_min:
                pos_min = tmp_min
            if pos_dict[n]< pos_dict[s-n]:
                ret = [n, s-n]
            else:
                ret = [s-n, n]
    print(ret)
    return ret



l1= [1, 4, 8, 7, 3, 15]
l2= [1, -2, 3, 0, -6, 1]
l3= [20, -13, 40]
l4= [1, 2, 3, 4, 1, 0]
l5= [10, 5, 2, 3, 7, 5]
l6= [4, -2, 3, 3, 4]
l7= [0, 2, 0]
l8= [5, 9, 13, -3]

print("Testing For Sum of Pairs")
#assert(sum_pairs(l1, 8) == [1, 7])
#assert(sum_pairs(l2, -6) == [0, -6])
#assert(sum_pairs(l3, -7) == None)
assert(sum_pairs(l4, 2) == [1, 1])
#assert(sum_pairs(l5, 10) == [3, 7])
#assert(sum_pairs(l6, 8) == [4, 4])
#assert(sum_pairs(l7, 0) == [0, 0])
#assert(sum_pairs(l8, 10) == [13, -3])

