# Find the odd int

def find_it(seq):
    if len(seq)==1:
        return seq[0]
    else:
        seq = sorted(seq)
        #print(seq)
        freq={}
        for i in seq:
            if i not in freq.keys():
                freq[i]=1
            else:
                freq[i]+=1
        #print(freq)
        ret=0
        for key, value in freq.items():
            if value%2==1:
                return key
    return ret

print("Example")
assert(find_it([20,1,-1,2,-2,3,3,5,5,1,2,4,20,4,-1,-2,5])==5)
