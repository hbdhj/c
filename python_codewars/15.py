# ASCII hex converter

class Converter():
    @staticmethod
    def to_ascii(h):
        ret=""
        for i in range(len(h)/2):
            hexed_letters=h[2*i]+h[2*i+1];
            ret+=chr(int(hexed_letters, base=16));
        return ret

    @staticmethod
    def to_hex(s):
        ret="";
        for letter in s:
            converted_letter=str(hex(ord(letter)));
            ret+=converted_letter[2:];
        return ret

s="Look mom, no hands";
h="4c6f6f6b206d6f6d2c206e6f2068616e6473";
Converter.to_hex(s);
Converter.to_ascii(h);
