/*

Copyright 2017 <Deng Haijun>

Dashboard > Tutorials > Cracking the Coding Interview > Stacks: Balanced Brackets 

Sample Input

3
{[()]}
{[(])}
{{[[(())]]}}

Sample Output

YES
NO
YES

*/

#include "./common.h"

bool is_balanced(string expression) {
    stack<char> Brackets;
    for (int i = 0; i < expression.length(); i++) {
        switch (expression[i]) {
            case '(':
            case '[':
            case '{':
                Brackets.push(expression[i]);
                break;
            case ')':
                if (Brackets.size() > 0 && Brackets.top() == '(')
                    Brackets.pop();
                else
                    return false;
                break;
            case ']':
                if (Brackets.size() > 0 && Brackets.top() == '[')
                    Brackets.pop();
                else
                    return false;
                break;
            case '}':
                if (Brackets.size() > 0 && Brackets.top() == '{')
                    Brackets.pop();
                else
                    return false;
                break;
            default:
                break;
        }
    }
    if (Brackets.size())
        return false;
    else
        return true;
}

int main() {
    int t;
    cin >> t;
    for (int a0 = 0; a0 < t; a0++) {
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if (answer)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}