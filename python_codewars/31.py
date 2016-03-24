# Did you mean ...?
class Dictionary:
    def __init__(self,words):
        self.words=words

    def find_most_similar(self, term):
        most_dis = len(term)
        ret = ""
        for word in self.words:
            new_dis = EditDis(word, term)
            if new_dis < most_dis:
                ret = word
                most_dis = new_dis

        return ret
    
def EditDis(word1, word2):
    len_1=len(word1)
    len_2=len(word2)

    x =[[0]*(len_2+1) for _ in range(len_1+1)]#the matrix whose last element ->edit distance

    for i in range(0,len_1+1): #initialization of base case values
        x[i][0]=i
    for j in range(0,len_2+1):
        x[0][j]=j
    for i in range (1,len_1+1):
        for j in range(1,len_2+1):
            if word1[i-1]==word2[j-1]:
                x[i][j] = x[i-1][j-1]
            else :
                x[i][j]= min(x[i][j-1], x[i-1][j], x[i-1][j-1])+1

    return x[i][j]

words=['cherry', 'peach', 'pineapple', 'melon', 'strawberry', 'raspberry', 'apple', 'coconut', 'banana']
test_dict=Dictionary(words)
assert(test_dict.find_most_similar('strawbery')=='strawberry')
assert(test_dict.find_most_similar('berry')=='cherry')
assert(test_dict.find_most_similar('aple')=='apple')