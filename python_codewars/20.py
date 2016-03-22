# Explosive Sum

def exp_sum(n):
    #known_list = [0, 1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42, 56, 77, 101, 135, 176, 231, 297, 385, 490, 627, 792, 1002, 1255, 1575, 1958, 2436, 3010, 3718, 4565, 5604, 6842, 8349, 10143, 12310, 14883, 17977, 21637, 26015, 31185, 37338, 44583, 53174, 63261, 75175, 89134, 105558, 124754, 147273, 173525]
    known_list = [1, 1, 2, 3, 5, 7, 11, 15, 22, 30, 42]
    if n<0:
        return 0
    else:
        ret_list=list(1, n+1)
        if n>1:
            step = 2
            print(n+1, len(ret_list), range(step, n+1, step))
            for i in range(step, n+1, step):
                print(i)
                ret_list[i]+=1
            step+=1
        print(ret_list)
        return ret_list[n]
#print(exp_sum(-1), 0)
#print(exp_sum(0), 1)
#print(exp_sum(1), 1)
print(exp_sum(2), 2)
print("==============")
print(exp_sum(3), 3)
print("==============")
print(exp_sum(4), 5)
#print(exp_sum(5), 7)
#print(exp_sum(10), 42)
#print(exp_sum(11), 56)
#print(exp_sum(12), 77)
#print(exp_sum(13), 101)