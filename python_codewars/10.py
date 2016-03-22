# Common Denominators

def convertFracts(lst):
    merged_lst=[]
    for sub_lst in lst:
        #if sub_lst[0] not in merged_lst:
        #    merged_lst.append(sub_lst[0]);
        if sub_lst[1] not in merged_lst:
            merged_lst.append(sub_lst[1]);
    #print(merged_lst);
    def gcd(op1, op2):
        if (op2==0): return op1
        else: return gcd(op2, op1%op2)
    def lcm(op1, op2):
        g=gcd(op1, op2);
        l=op1/g*op2;
        #print("gcd of ",op1," ",op2," = ",g," and lcm = ",l);
        return l
    l=1;
    for n in merged_lst:
        if n!=1:
            l=lcm(l,n);
        #print(l);
    ret=[]
    for sub_lst in lst:
        re=[]
        re.append(l/sub_lst[1]*sub_lst[0]);
        re.append(l);
        ret.append(re);
    print(ret);
    return ret;
  
a = [[1, 2], [1, 3], [1, 4]];
convertFracts(a);
b = [[12, 84], [28, 84], [7, 84]];
convertFracts(b);
