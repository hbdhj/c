# Strings Mix

def mix(s1, s2):
    if s1 == s2:
        return ""
    else:
        map1 = {}
        for c1 in s1:
            if c1.isalpha() and c1.islower():
                if c1 in map1.keys():
                    map1[c1]+=1
                else:
                    map1[c1]=1
        map2 = {}
        for c2 in s2:
            if c2.isalpha() and c2.islower():
                if c2 in map2.keys():
                    map2[c2]+=1
                else:
                    map2[c2]=1
        #print(map1)
        #print(map2)
        merged = {}
        for c1, n1 in map1.items():
            if n1 > 1:
                merged[c1] = (1,n1)
        for c2, n2 in map2.items():
            if n2 > 1:
                if c2 in merged.keys():
                    #print(n2, merged[c1][1])
                    if n2 > merged[c2][1]:
                        merged[c2] = (2,n2)
                    elif n2 == merged[c2][1]:
                        merged[c2] = (0,n2)
                else:
                    merged[c2] = (2,n2)
        print(merged)
        def numeric_compare(x, y):
            if x[1][1]==y[1][1]:
                return x[0]-y[0]
            else:
                return x[1][1]-y[1][1]

        sorted_merged = sorted(merged.items(), key=lambda x: x[1][1], reverse=True)
        #sorted_merged = sorted(merged.items(), cmp=numeric_compare)
        print(sorted_merged)
        ret_list = []
        for c, v in sorted_merged:
            ret_str = ""
            if v[0]==0:
                ret_str = "=:"
            else:
                ret_str = str(v[0])+":"
            for i in range(v[1]):
                ret_str+=c
            ret_list.append(ret_str)
        print(ret_list)
        return '/'.join(ret_list)


print("Mix")
print("Basic Tests")
assert(mix("Are they here", "yes, they are here")=="2:eeeee/2:yy/=:hh/=:rr")
#assert(mix("looping is fun but dangerous", "less dangerous than coding")=="1:ooo/1:uuu/2:sss/=:nnn/1:ii/2:aa/2:dd/2:ee/=:gg")
#assert(mix(" In many languages", " there's a pair of functions")=="1:aaa/1:nnn/1:gg/2:ee/2:ff/2:ii/2:oo/2:rr/2:ss/2:tt")
#assert(mix("Lords of the Fallen", "gamekult")=="1:ee/1:ll/1:oo")
#assert(mix("codewars", "codewars")=="")
#assert(mix("A generation must confront the looming ", "codewarrs")=="1:nnnnn/1:ooooo/1:tttt/1:eee/1:gg/1:ii/1:mm/=:rr")