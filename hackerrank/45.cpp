/*
Artificial Intelligence > Bot Building > Bot saves princess

Sample input

3
---
-m-
p--

Sample output

DOWN
LEFT

*/

#include <iostream>
#include <vector>
using namespace std;
void displayPathtoPrincess(int n, vector <string> grid)
{
    int px, py, mx, my;
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (grid[i][j] == 'p')
            {
                px = j;
                py = i;
            }
            else if (grid[i][j] == 'm')
            {
                mx = j;
                my = i;
            }
        }
    }
    if (py>my)
    {
        for (int i = 0; i<(py - my); i++)
            cout<<"DOWN"<<endl;
    }
    else if (my>py)
    {
        for (int i = 0; i<(my - py); i++)
            cout<<"UP"<<endl;
    }
    if (px>mx)
    {
        for (int i = 0; i<(px - mx); i++)
            cout<<"RIGHT"<<endl;
    }
    else if (mx>px)
    {
        for (int i = 0; i<(mx - px); i++)
            cout<<"LEFT"<<endl;
    }
}

int main(void)
{
    int m;
    vector <string> grid;

    cin >> m;

    for(int i=0; i<m; i++)
    {
        string s; cin >> s;
        grid.push_back(s);
    }

    displayPathtoPrincess(m,grid);

    return 0;
}
