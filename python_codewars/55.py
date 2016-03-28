# Text align justify

def justify(text, width):
    length = 0
    for word in text.split():
        length+=len(word)+1
        if length > width:
            line_length =length-len(word)
            print(line_length)
    return ''

assert(justify('123 45 6', 7)=='123 45\n6')