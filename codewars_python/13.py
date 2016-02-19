def okkOokOo(s):
    translate={"Ok, Ook, Ooo":'H', 
               "Okk, Ook, Ok":'e',
               "Okk, Okk, Oo":'l', 
               "Okk, Okkkk":'o',
               "Ok, Ok, Okkk":'W',
               "Okkk, Ook, O":'r',
               "Okk, Ook, Oo":'d',
               "Ook, Ooook":'!'};
    if s[-1]=='!':
        s=s[:-1];
    split_res=s.split('?');
    ret="";
    for word in split_res:
        if word.strip() in translate.keys():
            ret+=translate[word.strip()];
    print(ret)
    return ret


okkOokOo('Ok, Ook, Ooo?  Okk, Ook, Ok?  Okk, Okk, Oo?  Okk, Okk, Oo?  Okk, Okkkk!')  # -> 'Hello'
okkOokOo('Ok, Ok, Okkk?  Okk, Okkkk?  Okkk, Ook, O?  Okk, Okk, Oo?  Okk, Ook, Oo?  Ook, Ooook!')  # -> 'World!'
