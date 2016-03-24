# Matrix Determinant

def determinant(matrix):
    if len(matrix)==1:
        return matrix[0][0]
    elif len(matrix)==2:
        return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0]
    elif len(matrix)>2:
        ret = 0
        for i in range(len(matrix)):
            left = []
            for j in range(1,len(matrix)):
                left_row = []
                for k in range(0,len(matrix)):
                    if k!=i:
                        left_row.append(matrix[j][k])
                left.append(left_row)
            #print(ret, matrix[0][i], left)
            if i%2==0:
                ret += matrix[0][i]*determinant(left)
            else:
                ret -= matrix[0][i]*determinant(left)
        return ret

print(determinant([ [1, 3], [2,5]]))
print(determinant([ [2,5,3], [1,-2,-1], [1, 3, 4]]))