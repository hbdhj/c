/*

Copyright 2017 <Deng Haijun>

*/

#include <vector>


using std::vector;


int main() {
    int r = 10;
    int c = 1000;
    int s = 100;
    vector<vector<int*> > matrix1(r);
    for (int i = 0; i < r; i++) {
        matrix1[i].resize(c);
        for (int j = 0; j < c; j++) {
            matrix1[i][j] = new int[s];
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            delete matrix1[i][j];
        }
    }
    vector<vector<int*> > matrix2(c);
    for (int i = 0; i < c; i++) {
        matrix2[i].resize(r);
        for (int j = 0; j < r; j++) {
            matrix2[i][j] = new int[s];
        }
    }
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            delete matrix2[i][j];
        }
    }
    return 0;
}
