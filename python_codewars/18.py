def validBraces(string):
    braces=[]
    for ch in string:
        if len(braces):
            lastCh = braces[-1]
            #print(lastCh, ch)
            if lastCh=='(':
                if ch ==')':
                    braces=braces[:-1]
                elif ch ==']' or ch =='}':
                    return False
                else:
                    braces.append(ch)
            if lastCh=='[':
                if ch ==']':
                    braces=braces[:-1]
                elif ch ==')' or ch =='}':
                    return False
                else:
                    braces.append(ch)
            if lastCh=='{':
                if ch =='}':
                    braces=braces[:-1]
                elif ch ==')' or ch ==']':
                    return False
                else:
                    braces.append(ch)
        else:
            if ch == '[' or ch == '{' or ch == '(':
                braces.append(ch)
            else:
                return False
        #print(braces)
    return len(braces)==0

print(validBraces( "()" ))
print(validBraces( "())(" ))
print(validBraces( "[(])" ))
print(validBraces( "[()]" ))
print(validBraces( "(){}[]" ))
print(validBraces( "(}" ))
print(validBraces( "([{}])" ))
