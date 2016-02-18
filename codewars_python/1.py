def pattern(n):
    # Happy Coding ^_^
    ret="";
    if n<1:
        return ret;
    for i in range(1,n+1):
        print("i = %d", i)
        j=n
        while j>=i:
            print("j = %d", j)
            ret=ret+str(j)
            j-=1;
        if i<n:
            ret=ret+'\n';
    print(ret)
    return ret;

pattern(1)
print()
pattern(10)
