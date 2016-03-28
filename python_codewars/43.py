# Function iteration

def create_iterator(func, num):
    # TODO: Write code here to return a function
    # that executes *func*, *n* times on a supplied input
    def multiple_func(p):
        ret = p
        n = num
        while n>0:
            ret=func(ret)
            n-=1
        return ret
    return multiple_func

print("Iterator for 'get_double' function")
def get_double(n):
    return 2*n

print("Running the iterator for once")
double_iterator = create_iterator(get_double, 1)

assert(double_iterator(3)==6)
assert(double_iterator(5)==10)

print("Running the iterator twice")
get_quadruple = create_iterator(get_double, 2)

assert(get_quadruple(2)==8)
assert(get_quadruple(5)==20)