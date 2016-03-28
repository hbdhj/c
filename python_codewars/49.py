# Decode the Morse code

def decodeMorse(morseCode):
    # ToDo: Accept dots, dashes and spaces, return human-readable message
    print(morseCode)
    word_list = []
    for word in morseCode.split('   '):
        letter_list=[]
        for letter in word.strip().split():
            letter_list.append(MORSE_CODE[letter.strip()])
        word_list.append(''.join(letter_list))
    return (' '.join(word_list)).strip()