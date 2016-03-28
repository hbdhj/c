# Number Shortening Filter

def shorten_number(suffixes, base):
    #your code here
    def ret_filter(input):
        #print(input)
        if type(input)==str:
            if input.isdigit():
                n=int(input);
                bit_map = []
                b = 1
                for suffix in suffixes:
                    bit_map.append((b, suffix))
                    b*=base
                #print(bit_map)
                ret = ""
                for item in bit_map:
                    if n> item[0]:
                        ret = str(int(n/item[0]))+item[1]
                        #print(ret)
                return ret
            else:
                return str(input);
        else:
            return str(input)
    return ret_filter;

print("Basic tests")
filter1 = shorten_number(['','k','m'],1000)
assert(filter1('234324')=='234k')
assert(filter1('98234324')== '98m')
assert(filter1([1,2,3])== '[1, 2, 3]')
assert(filter1('')== '')
assert(filter1('32424234223')=='32424m')
filter2 = shorten_number(['','KB','MB','GB'],1024)
assert(filter2('32')=='32')
assert(filter2('2100')=='2KB')
assert(filter2('pippi')== 'pippi')
assert(filter2('2100k')=='2100k')
assert(filter2('1073741823')=='1023MB')
