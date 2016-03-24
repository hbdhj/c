# Make a spiral
#[[1,1,1,1,1],
# [0,0,0,0,1],
# [1,1,1,0,1],
# [1,0,0,0,1],
# [1,1,1,1,1]]

def spiralize(size):
    # Make a snake
    spiral = []
    for i in range(size):
        spiral_row = []
        for j in range(size):
            spiral_row.append(0)
        spiral.append(spiral_row)
    #print(spiral)
    for i in range(size):
        spiral[0][i]=1 # first row
        spiral[i][size-1]=1 # last col
    if size > 2:
        for i in range(size):
            spiral[size-1][i]=1 # last col
    if size > 3:
        for i in range(2, size):
            spiral[i][0]=1 # last col
    if size > 4:
        if size%2==0:
            pass
        else:
            pass

    return spiral
def print_spiralize(spiral):
    print("============= " + str(len(spiral))+ " =============")
    for row in spiral:
        print(row)
#print_spiralize(spiralize(1))
#print_spiralize(spiralize(2))
#print_spiralize(spiralize(3))
#print_spiralize(spiralize(4))
print_spiralize(spiralize(5))
print_spiralize(spiralize(6))
print_spiralize(spiralize(7))
print_spiralize(spiralize(8))



