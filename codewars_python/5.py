def ret_filter(inputi, suffixes, base):
    if isinstance(input, str):
        if input.isdigit():
            n=int(input);
            bit=0;
            while n>base:
                n=int(n/base);
                bit+=1;
            if bit<len(suffixes):
                return str(n)+suffixes[bit];
            else:
                return "";
        else:
            return str(input);
    else:
        return input;
ret_filter([1,2,3], ['','k','m'], 1000);
