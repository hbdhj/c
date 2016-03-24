# Human readable duration format

def format_duration(seconds):
    time_dict = {365*24*3600:'year',
                 24*3600:'day',
                 3600:'hour',
                 60:'minute',
                 1:'second',
                 }
    #print(time_dict)
    ret_list =[]

    for num in sorted(time_dict.keys(), reverse=True):
        if seconds==0:
            break
        #print(seconds, num, time_dict[num])
        if seconds>=num:
            n = int(seconds/num)
            if n>1:
                ret_list .append( str(n) + ' ' + time_dict[num] + 's')
            else:
                ret_list .append( str(n) + ' ' + time_dict[num] )
            seconds -= n*num

    #print(ret_list)
    ret = ""
    if len(ret_list)>1:
        for item in range(len(ret_list)-2):
            ret += ret_list[item] + ", "
        ret += ret_list[-2] + " and " + ret_list[-1]
    elif len(ret_list)==1:
        ret = ret_list[0]
    else:
        ret = "now"
    #print(ret)
    return ret
assert(format_duration(0)=="now")
assert(format_duration(1)=="1 second")
assert(format_duration(62)=="1 minute and 2 seconds")
assert(format_duration(120)=="2 minutes")
assert(format_duration(3600)=="1 hour")
assert(format_duration(3662)=="1 hour, 1 minute and 2 seconds")
assert(format_duration(56*3600+135)=="2 days, 8 hours, 2 minutes and 15 seconds")
