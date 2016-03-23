# The Millionth Fibonacci Kata

fib_list = [0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765]
def fib(n):
    while len(fib_list) < 150:
        fib_list.append(fib_list[len(fib_list)-1]+fib_list[len(fib_list)-2])
    return fib_list[n]

print(fib(0))
print(fib(1))
print(fib(2))
print(fib(3))
print(fib(10))
print(fib(11))
print(fib(12))
#print(fib(1500000))