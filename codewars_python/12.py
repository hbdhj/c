def pascal(p):
    #your code here
    if p==1:
        return [[1]];
    elif p==2:
        return [[1],[1,2]];
    ret = [[1],[1,1]];
    for i in range(1, p-1):
        #print(i);
        re=[1];
        for j in range(i):
            #print(j);
            re.append(ret[i][j]+ret[i][j+1]);
        re.append(1);
        ret.append(re);
        #print(ret);
    return ret;

pascal(1);
pascal(3);
pascal(5);
