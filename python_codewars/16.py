# Nesting Structure Comparison
# Complete the method (or function in Python) to return true when its argument is an array that has the same nesting structure as the first array.

def same_structure_as(original, other):
    if not isinstance(original, list) and not isinstance(other, list):
        return True
    if not isinstance(original, list) and isinstance(other, list):
        return False
    if isinstance(original, list) and not isinstance(other, list):
        return False
    if len(original)!=len(other):
        return False
    same = True
    for i in range(len(original)):
        same = same_structure_as(original[i], other[i])
        if same == False:
            break
    return same

# True
print(same_structure_as([1,[1,1]],[2,[2,2]]))
print(same_structure_as([ 1, 1, 1 ], [ 2, 2, 2 ] ))
print(same_structure_as([ 1, [ 1, 1 ] ], [ 2, [ 2, 2 ] ] ))
print(same_structure_as([ [ [ ], [ ] ] ], [ [ [ ], [ ] ] ] ))
print(same_structure_as(1, 2))
print(same_structure_as([1,'[',']'], ['[',']',1]))

# False
print(same_structure_as([ 1, [ 1, 1 ] ], [ [ 2, 2 ], 2 ] ))
print(same_structure_as([ 1, [ 1, 1 ] ], [ [ 2 ], 2 ] ))
print(same_structure_as([1,[1,1]],[[2,2],2]))
print(same_structure_as([ [ [ ], [ ] ] ], [ [ 1, 1 ] ] ))
