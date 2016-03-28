# Your order, please

def order(sentence):
    if len(sentence)==0:
        return ""
    words = {}
    for word in sentence.split():
        for letter in word:
            if letter.isdigit():
                words[int(letter)]=word
    #print(words)
    ret_list = []
    for key in sorted(words.keys()):
        ret_list.append(words[key])
    #print(ret_list)
    return ' '.join(ret_list)

assert(order("is2 Thi1s T4est 3a")=="Thi1s is2 3a T4est")