#  The observed PIN
# ┌───┬───┬───┐
# │ 1 │ 2 │ 3 │
# ├───┼───┼───┤
# │ 4 │ 5 │ 6 │
# ├───┼───┼───┤
# │ 7 │ 8 │ 9 │
# └───┼───┼───┘
#     │ 0 │
#     └───┘


def get_pins(observed):
    #print("====================")
    map = { '0':['0','8'],
            '1':['1','2','4'],
            '2':['1','2','5','3'],
            '3':['2','3','6'],
            '4':['1','4','5','7'],
            '5':['2','4','5','6','8'],
            '6':['1','2','4'],
            '7':['4','7','8'],
            '8':['0', '5','7','8','9'],
            '9':['6','8','9']}
    num = 1
    for ch in observed:
        num *= len(map[ch])
    #print(num)
    ret = []
    l = len(observed)
    for n in range(num):
        #print(n)
        ret_str=''
        for i in range(l):
            c = observed[l-i-1]
            #print(c)
            ret_str= map[c][n%len(map[c])] + ret_str
        #print(ret_str)
        ret.append(ret_str)
    return(ret)

#print(get_pins('8'))
#print(get_pins('11'))
print(get_pins('369'))
