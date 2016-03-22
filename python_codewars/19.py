# Strip Comments

def solution(string, markers):
    splited_str = string.split('\n')
    ret_str = []
    for str in splited_str:
        index = len(str)
        for marker in markers:
            pos = str.find(marker)
            if pos >= 0 and pos < index:
                    index = pos
        ret_str.append(str[:index].strip())
    return '\n'.join(ret_str)

print(solution("apples, pears # and bananas\ngrapes\nbananas !apples", ["#", "!"]))
# "apples, pears\ngrapes\nbananas"
print(solution("a #b\nc\nd $e f g", ["#", "$"]))
# "a\nc\nd")