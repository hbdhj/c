def likes(names):
    #your code here
    append=" likes this";
    name_chain="";
    if len(names)==0:
        name_chain="no one";
    elif len(names)==1:
        name_chain=names[0];
    elif len(names)==2:
        name_chain=names[0]+" and "+names[1];
    elif len(names)>2:
        name_chain = names[0];
        for name in names[1:-2]:
            print(name);
            name_chain+=", "+name;
        name_chain+=", " + names[-2]+" and "+names[-1]     
    return name_chain+append;

print(likes(['Peter']));
print(likes(['Jacob', 'Alex']));
print(likes(['Max', 'John', 'Mark']));
print(likes(['Alex', 'Jacob', 'Mark', 'Max']));
