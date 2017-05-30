/*
Copyright 2017 <Deng Haijun>

Artificial Intelligence > Bot Building > BotClean

Sample Input #00

0 0
b---d
-d--d
--dd-
--d--
----d

Sample Output #00

RIGHT

Resultant state

-b--d
-d--d
--dd-
--d--
----d

Sample Input #01

0 1
-b--d
-d--d
--dd-
--d--
----d

Sample Output #01

DOWN

Resultant state

----d
-d--d
--dd-
--d--
----d

*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void next_move(int posr, int posc, vector <string> board) {
    int size = 5;
    int dr, dc;
    int dmr = size * 2;
    int dmc = size * 2;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 'd') {
                dr = j;
                dc = i;
                if ((abs(dr - posr)+abs(dc - posc)) <
                    (abs(dmr - posr) + abs(dmc - posc))) {
                    dmr = dr;
                    dmc = dc;
                }
            }
        }
    }
    // cout<<"dmr = "<<dmr<<", dmc = "<<dmc<<endl;

    if (dmc > posc) {
        cout << "RIGHT" << endl;
    } else if (posc > dmc) {
        cout << "LEFT" << endl;
    } else {
        if (dmr > posr) {
            cout << "DOWN" << endl;
        } else if (posr > dmr) {
            cout << "UP" << endl;
        }
    }
}

int main(void) {
    int pos[2];
    vector <string> board;
    cin >> pos[0] >> pos[1];
    for (int i=0; i <5 ; i++) {
        string s;
        cin >> s;
        board.push_back(s);
    }
    next_move(pos[0], pos[1], board);
    return 0;
}
