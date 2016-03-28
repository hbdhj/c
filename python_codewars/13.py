# Ookkk, Ok, O? Ook, Ok, Ooo!

def okkOokOo(s):
    if s[-1]=='!':
        s=s[:-1];
    split_res=s.split('?');
    ret="";
    for word in split_res:
        ascii_code=0
        for letter in word.lower():
            if letter=='k':
                ascii_code=ascii_code*2+1
            if letter=='o':
                ascii_code*=2
            print(word, letter, ascii_code)
        ret+=chr(ascii_code)
    print(ret)
    return ret


okkOokOo('Ok, Ook, Ooo?  Okk, Ook, Ok?  Okk, Okk, Oo?  Okk, Okk, Oo?  Okk, Okkkk!')  # -> 'Hello'
okkOokOo('Ok, Ok, Okkk?  Okk, Okkkk?  Okkk, Ook, O?  Okk, Okk, Oo?  Okk, Ook, Oo?  Ook, Ooook!')  # -> 'World!'
