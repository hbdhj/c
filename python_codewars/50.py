# Maximum subarray sum

def maxSequence(arr):
    '''
    if len(arr)==0:
        return 0
    max_sum=0
    for i in range(1, len(arr)+1):
        for s in range(0, len(arr)):
            su = sum(arr[s:s+i])
            #print(i, s, su)
            if su>max_sum:
                max_sum =su
    #print(max_sum)
    return max_sum
    '''
    max,curr=0,0
    for x in arr:
        curr+=x
        if curr<0:curr=0
        if curr>max:max=curr
        print(x, curr, max)
    return max

print("Tests")
print('should work on an empty array')
assert(maxSequence([])==0)
print('should work on the example')
assert(maxSequence([-2, 1, -3, 4, -1, 2, 1, -5, 4])==6)