def count_change(money, coins):
    if len(coins) == 1:
        if money%coins[0]==0:
            return 1
        else:
            return 0
    else:
        coins=sorted(coins, reverse=True)
        #print(coins)
        ret = 0
        for n in range(0, money+1, coins[0]):
            ret += count_change(money-n, coins[1:])
        #print(ret)
        return ret

assert(3==count_change(4, [1,2]))
assert(4==count_change(10, [5,2,3]))
assert(0==count_change(11, [5,7]))