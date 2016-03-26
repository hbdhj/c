# The Clockwise Spiral
def createSubSpiral(dim, num):
    #print(dim, num)
    last = num * num
    if dim == 1:
        return [[last]]
    if dim == 2:
        return [[last-3, last-2], [last, last-1]]
    if dim == 3:
        return [[last-8, last-7, last-6], [last-1, last, last-5], [last-2, last-3, last-4]]
    if dim > 3:
        center = createSubSpiral(dim-2, num)
        #print(center)
        firstLine = []
        lastLine = []
        ret = []
        start = last-dim*dim + 1
        for i in range(dim):
            firstLine.append(i+start)
            lastLine.append(3*dim -i+start-3)
        #print(firstLine)
        #print(lastLine)
        ret.append(firstLine)
        for i in range(1, dim-1):
            line = [4*dim - i +start -4]
            line += center[i-1]
            line.append(start+dim+i-1)
            #print(i, line)
            ret.append(line)
        ret.append(lastLine)
        #print(ret)
        return ret


def createSpiral(N):
    return createSubSpiral(N, N)

def printMatrix(mtrx):
    for line in mtrx:
        print(line)

printMatrix(createSpiral(8))