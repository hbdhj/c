/*
Data Structures > Heap > QHEAP1

Sample Input

5
1 4
1 9
3
2 4
3

Sample Output

4
9

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

using namespace std;

class MinHeap
{
private:
    list<int> values;
public:
    MinHeap()
    {
    };

    void add(int value)
    {
        if (values.size())
        {
            bool inserted = false;
            for (list<int>::iterator it=values.begin(); it!=values.end(); ++it)
            {
                if (*it>value)
                {
                    values.insert(it, value);
                    break;
                }
            }
            if (inserted==false)
                values.push_back(value);
        }
        else
            values.push_front(value);
    };

    void remove(int value)
    {
        values.remove(value);
    };

    int min()
    {
        if (values.size())
        {
            return values.front();
        }
        return -1;
    };

    void print()
    {
        for (list<int>::iterator it=values.begin(); it!=values.end(); ++it)
        {
            cout<<" "<<*it;
        }
        cout<<endl;
    };
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int action, val;
    cin >> n;
    MinHeap heap;
    for (int i = 0; i < n; i++)
    {
        cin >> action;
        //cout<< "action is "<<action<<", val is "<<val<<endl;
        if (action == 1)
        {
            cin  >> val;
            //cout<<"add value "<<val<<endl;
            heap.add(val);
            //heap.print();
        }
        else if (action == 2)
        {
            cin >> val;
            //cout<<"remove value "<<val<<endl;
            heap.remove(val);
            //heap.print();
        }
        else if (action == 3)
        {
            //cout<<"get the min "<<endl;
            cout<<heap.min()<<endl;
        }
    }
    return 0;
}
