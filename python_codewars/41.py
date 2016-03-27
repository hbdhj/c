# Valid Sudoku
import math

class Sudoku(object):
    #your code here
    def __init__(self, matrix):
        self.matrix = matrix

    def is_valid(self):
        print(self.matrix)
        if len(self.matrix)==0:
            return False
        if self.valid_format()==False:
            return False
        if self.valid_row()==False:
            return False
        if self.valid_col()==False:
            return False
        if self.valid_sub_matrix()==False:
            return False
        return True

    def valid_format(self):
        sub_len = int(math.sqrt(len(self.matrix)))
        if len(self.matrix)!=sub_len*sub_len:
            return False
        for sub_list in self.matrix:
            if len(sub_list)!=len(self.matrix):
                return False
        for sub_list in self.matrix:
            for elem in sub_list:
                print(elem)
                if type ( elem )!=int:
                    print(elem, "is not a int")
                    return False
                else:
                    print(elem, "is a int")

        return True

    def valid_row(self):
        for sub_list in self.matrix:
            if self.valid_list(sub_list)==False:
                return False
        return True

    def valid_col(self):
        for i in range(len(self.matrix)):
            sub_list = []
            for j in range(len(self.matrix)):
                sub_list.append(self.matrix[i][j])

            if self.valid_list(sub_list)==False:
                return False
        return True

    def valid_sub_matrix(self):
        sub_len = int(math.sqrt(len(self.matrix)))
        #print(sub_len)
        for i in range(sub_len):
            for j in range(sub_len):
                sub_list = []
                for m in range(sub_len):
                    for n in range(sub_len):
                        sub_list.append(self.matrix[sub_len*i+m][sub_len*j+n])
                #print(sub_list)
                if self.valid_list(sub_list)==False:
                    return False
        return True

    def valid_list(self, list):
        for num in range(1, len(list)+1):
            if num not in list:
                return False
        return True



goodSudoku1 = Sudoku([
  [7,8,4, 1,5,9, 3,2,6],
  [5,3,9, 6,7,2, 8,4,1],
  [6,1,2, 4,3,8, 7,5,9],

  [9,2,8, 7,1,5, 4,6,3],
  [3,5,7, 8,4,6, 1,9,2],
  [4,6,1, 9,2,3, 5,8,7],

  [8,7,6, 3,9,4, 2,1,5],
  [2,4,3, 5,6,1, 9,7,8],
  [1,9,5, 2,8,7, 6,3,4]
])

goodSudoku2 = Sudoku([
  [1,4, 2,3],
  [3,2, 4,1],

  [4,1, 3,2],
  [2,3, 1,4]
])

# Invalid Sudoku
badSudoku1 = Sudoku([
  [0,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],

  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],

  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9],
  [1,2,3, 4,5,6, 7,8,9]
])

badSudoku2 = Sudoku([
  [1,2,3,4,5],
  [1,2,3,4],
  [1,2,3,4],
  [1]
])

badSudoku3 = Sudoku([[True]])

print('should be valid')
assert(goodSudoku1.is_valid()==True)
#assert(goodSudoku2.is_valid()==True)

print('should be invalid')
#assert(badSudoku1.is_valid()==False)
#assert(badSudoku2.is_valid()==False)
assert(badSudoku3.is_valid()==False)