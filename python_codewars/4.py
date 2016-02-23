class Plugboard(object):
    board={};
    def __init__(self, wires):
        """
        wires: This is the mapping of pairs of characters
        """
        if len(wires)>20:
            print("")
        counter=0
        for letter in wires:
            if counter%2==0:
                self.board[letter]=wires[counter+1];
            else:
                self.board[letter]=wires[counter-1];
            counter+=1;
        print(self.board)        
    
    def process(self, c):
        """
        c: The single character to process
        """
        if c in self.board.keys():
             print(self.board[c]);
        else:
             print(c);

plugboard = Plugboard("ABCD")
plugboard.process('A')
plugboard.process('B')
plugboard.process('C')
plugboard.process('D')
plugboard.process('E')

