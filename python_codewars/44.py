# IQ Test

def iq_test(numbers):
    numbers=[int(i) for i in numbers.split()]
    #print(numbers)
    odd = 0
    even = 0
    for number in numbers:
        if number%2==0:
            even += 1
        else:
            odd += 1
    #print(odd, even)
    index = 1
    if odd == 1:
        for number in numbers:
            if number%2==1:
                return index
            index+=1
    if even == 1:
        for number in numbers:
            if number%2==0:
                return index
            index+=1
assert(iq_test("2 4 7 8 10")==3)
assert(iq_test("1 2 2")==1)