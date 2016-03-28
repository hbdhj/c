# Multiplication Tables

def multiplication_table(row, col):
    ret = []
    for i in range(row):
        lst = []
        for j in range(col):
            lst.append((i+1)*(j+1))
        ret.append(lst)
    #print(ret)
    return ret

assert(multiplication_table(2,2)==[[1,2],[2,4]])
assert(multiplication_table(3,3)==[[1,2,3],[2,4,6],[3,6,9]])