#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudokuLine(vector<char>& line) {
        vector<int> exist(9, 1);
        for (int i=0;i<line.size();i++)
            if(line[i]!='.')
                if (exist[line[i]-'1'])
                    exist[line[i]-'1']--;
                else
                    return false;
        return true;
    }
    bool isValidSudoku(vector<vector<char> >& board) {
        for (int i=0;i<board.size();i++)
            if (isValidSudokuLine(board[i])==false)
                return false;
        for (int i=0;i<board.size();i++) {
            vector<char> col;
            for (int j=0;j<board.size();j++)
                col.push_back(board[j][i]);
            if (isValidSudokuLine(col)==false)
                return false;
        }
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                vector<char> block;
                for (int m=0;m<3;m++)
                    for (int n=0;n<3;n++)
                        block.push_back(board[i*3+m][j*3+n]);
                if (isValidSudokuLine(block)==false)
                    return false;
            }
        }
        return true;
    }
};

vector<vector<char> > createBoard(string str) {
    vector<vector<char> > ret; 
    for (int i=0; i<9; i++) {
        vector<char> row;
        for (int j=0; j<9; j++)
            if ((i*9+j)<str.length())
                row.push_back(str[i*9+j]);
        ret.push_back(row);
    }
    
    return ret;
}

int main()
{
    //string str1 = "..5.....6....14.................92..5....2..........3....54....3.....42....27.6..";
    string str1 = "..4...63..........5......9....56....4.3.....1...7........5.......................";
    vector<vector<char> > board = createBoard(str1);
    Solution s;
    s.isValidSudoku(board);
}
