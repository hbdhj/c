# Which are in?

def in_array(array1, array2):
    # your code
    ret = []
    for item1 in array1:
        for item2 in array2:
            if item2.find(item1)>=0:
                if item1 not in ret:
                    ret.append(item1)
    return sorted(ret)

a1 = ["live", "arp", "strong"]
a2 = ["lively", "alive", "harp", "sharp", "armstrong"]
r = ['arp', 'live', 'strong']
assert(in_array(a1, a2)==r)