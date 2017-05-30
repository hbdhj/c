/*
Copyright 2017 <Deng Haijun>

Artificial Intelligence > Bot Building > Bot saves princess -2

Sample Input

5
2 3
-----
-----
p--m-
-----
-----

Sample Output

LEFT

*/

#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

void nextMove(int n, int r, int c, vector <string> grid) {
    int px, py, mx, my;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'p') {
                px = j;
                py = i;
            }
        }
    }
    if (py > r) {
        cout << "DOWN" << endl;
    } else if (r > py) {
        cout << "UP" << endl;
    }
    if (px > c) {
        cout << "RIGHT" << endl;
    } else if (c > px) {
        cout << "LEFT" << endl;
    }
}

int main(void) {
    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}
