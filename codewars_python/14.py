def is_merge(s, part1, part2):
    if len(part1)==0:
        if s==part2:
            return True
        else:
            return False
    if len(part2)==0:
        if s==part1:
            return True
        else:
            return False
    i=j=k=0;
    while i<len(s):
        if j<len(part1) and s[i]==part1[j]:
            j+=1;
            i+=1;
        elif k<len(part2) and s[i]==part2[k]:
            k+=1;
            i+=1;
        else:
            break;
    if i==len(s) and j==len(part1) and k==len(part2):
        return True
    else:
        return False

is_merge('codewars', 'code', 'wars');
is_merge('codewars', 'cdw', 'oears');
is_merge('codewars', 'cod', 'wars');
