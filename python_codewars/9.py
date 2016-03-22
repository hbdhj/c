# Valid Parentheses

def valid_parentheses(string):
    ret=0;
    for ch in string:
        if ch=='(':
            ret+=1;
        elif ch==')':
            ret-=1;
        if ret<0:
            break;
    #print(ret);
    if ret==0:
        return True;
    else:
        return False;
 
valid_parentheses("  (")
valid_parentheses(")test")
valid_parentheses("")
valid_parentheses("hi())(")
valid_parentheses("hi(hi)()")
