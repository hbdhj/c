# Make a spiral
#[[1,1,1,1,1],
# [0,0,0,0,1],
# [1,1,1,0,1],
# [1,0,0,0,1],
# [1,1,1,1,1]]

def spiralize(size):
    # Make a snake
    if size == 0:
        return []
    elif size == 1:
        return [[1]]
    elif size == 2:
        return [[1,1],[0,1]]
    elif size == 3:
        return [[1,1,1],[0,0,1],[1,1,1]]
    elif size == 4:
        return [[1, 1, 1, 1],[0, 0, 0, 1],[1, 0, 0, 1],[1, 1, 1, 1]]
    elif size == 5:
        return [[1, 1, 1, 1, 1],[0, 0, 0, 0, 1],[1, 1, 1, 0, 1],[1, 0, 0, 0, 1],[1, 1, 1, 1, 1]]
    elif size == 5:
        return [[1, 1, 1, 1, 1, 1],[0, 0, 0, 0, 0, 1],[1, 1, 1, 1, 0, 1],[1, 0, 0, 1, 0, 1],[1, 0, 0, 0, 0, 1],[1, 1, 1, 1, 1, 1]]
    else:
        ret = []
        sub_matrix = spiralize(size-4)
        ret.append([1]*size)
        ret.append([0]*(size-1)+[1])
        ret.append([1,1]+sub_matrix[0]+[0, 1])
        for i in range(1, len(sub_matrix)):
            ret.append([1,0]+sub_matrix[i]+[0,1])
        ret.append([1]+[0]*(size-2)+[1])
        ret.append([1]*size)
        #print(ret)
        return ret

def print_spiralize(spiral):
    print("============= " + str(len(spiral))+ " =============")
    for row in spiral:
        print(row)
#print_spiralize(spiralize(1))
#print_spiralize(spiralize(2))
#print_spiralize(spiralize(3))
#print_spiralize(spiralize(4))
#print_spiralize(spiralize(5))
#print_spiralize(spiralize(6))
#print_spiralize(spiralize(7))
#print_spiralize(spiralize(8))
#print_spiralize(spiralize(9))
#print_spiralize(spiralize(10))



