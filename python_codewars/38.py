#  Reverse polish notation calculator
def eval(str):
    if str.find('.')<0:
        return int(str)
    else:
        return float(str)

def isOp(op):
    if op == '+' or op == '-' or op == '*' or op == '/':
        return True
    else:
        return False
def singlecalc(num1, num2, op):
    if op == '+':
        return str(num1 + num2)
    if op == '-':
        return str(num1 - num2)
    if op == '*':
        return str(num1 * num2)
    if op == '/':
        return str(num1 / num2)

def calc(expr):
    # TODO: Your awesome code here
    elems = expr.split()
    #print(expr, elems, len(elems))
    if len(elems)==0:
        return 0
    opFound = False
    for op in elems:
        if op == '+' or op == '-' or op == '*' or op == '/':
            opFound = True
    if opFound:
        while(opFound):
            Rst_lst = elems[:2]
            for i in range(2, len(elems)):
                #print('line 37', i, elems, Rst_lst)
                if isOp(elems[i])==True and isOp(elems[i-1])==False and isOp(elems[i-2])==False:
                    #print('line 39', Rst_lst)
                    Rst_lst = Rst_lst[:-2]
                    #print('line 41', Rst_lst)
                    Rst_lst.append(singlecalc(eval(elems[i-2]), eval(elems[i-1]), elems[i]))
                    #print('line 43', Rst_lst)
                else:
                    Rst_lst.append(elems[i])
            #print('line 46', elems, Rst_lst)
            opFound = False
            elems = Rst_lst
            #print(elems)
            for op in elems:
                if op == '+' or op == '-' or op == '*' or op == '/':
                    opFound = True
        return eval(elems[-1])
    else:
        return eval(elems[-1])

#assert(calc("")==0)
#assert(calc("1 2 3")==3)
#assert(calc("1 2 3.5")==3.5)
#assert(calc("1 3 +")==4)
#assert(calc("1 3 *")==3)
#assert(calc("1 3 -")==-2)
#assert(calc("4 2 /")==2)
#assert(calc("1 2 + 4 *")==12)
#assert(calc("5 1 2 + 4 * +")==17)
assert(calc("5 1 2 + 4 * + 3 -")==14)