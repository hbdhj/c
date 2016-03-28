# The Enigma Machine - Part 1: The Plugboard

class Plugboard(object):
    board={};
    def __init__(self, wires=[]):
        """
        wires: This is the mapping of pairs of characters
        """
        print(wires)
        if len(wires)>20:
            raise Exception("Should not have accepted too many wires defined");
            return;
        self.board = {}
        counter=0
        for letter in wires:
            if letter in self.board.keys():
                raise Exception("Should not have accepted a second definition for a wire end");
                break
            if counter%2==0:
                self.board[letter]=wires[counter+1];
            else:
                self.board[letter]=wires[counter-1];
            counter+=1;

    def process(self, c):
        """
        c: The single character to process
        """
        print(self.board)
        print(c)
        if c in self.board.keys():
             return(self.board[c]);
        else:
             return(c);

plugboard = Plugboard("ABCD")
plugboard.process('A')
plugboard.process('B')
plugboard.process('C')
plugboard.process('D')
plugboard.process('E')

