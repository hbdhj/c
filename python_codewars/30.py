# Pick peaks

def pick_peaks(arr):
    ret = {"pos":[], "peaks":[]}
    plateau = False
    plateau_start = 0
    for i in range(1,len(arr)-1):
        if arr[i]> arr[i-1] and arr[i]> arr[i+1]:
            ret["pos"].append(i)
            ret["peaks"].append(arr[i])
        if arr[i]> arr[i-1] and arr[i] == arr[i+1]:
            plateau = True
            plateau_start = i
        if arr[i]> arr[i-1] and arr[i] < arr[i+1]:
            if plateau == True:
                plateau = False
        if arr[i]== arr[i-1] and arr[i] > arr[i+1]:
            if plateau == True:
                ret["pos"].append(plateau_start)
                ret["peaks"].append(arr[i])
                plateau = False
                plateau_start = 0
    #print(ret)
    return ret

print('should support finding peaks')
assert(pick_peaks([1,2,3,6,4,1,2,3,2,1])=={"pos":[3,7], "peaks":[6,3]})

print('should support finding peaks, but should ignore peaks on the edge of the array')
assert(pick_peaks([3,2,3,6,4,1,2,3,2,1,2,3])=={"pos":[3,7], "peaks":[6,3]})

print('should support finding peaks; if the peak is a plateau, it should only return the position of the first element of the plateau')
assert(pick_peaks([3,2,3,6,4,1,2,3,2,1,2,2,2,1])=={"pos":[3,7,10], "peaks":[6,3,2]})

print('should support finding peaks; if the peak is a plateau, it should only return the position of the first element of the plateau')
assert(pick_peaks([2,1,3,1,2,2,2,2,1])=={"pos":[2,4], "peaks":[3,2]})

print('should support finding peaks, but should ignore peaks on the edge of the array')
assert(pick_peaks([2,1,3,1,2,2,2,2])=={"pos":[2], "peaks":[3]})