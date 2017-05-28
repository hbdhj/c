/*
Data Structures > Trie > Contacts

Sample Input

4
add hack
add hackerrank
find hac
find hak

Sample Output

2
0

*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class TrieNode
{
private:
    vector<TrieNode*> subNodes;
    int count;
public:
    TrieNode()
    {
        subNodes.resize(26);
        for (int i = 0; i<26; i++)
        {
            subNodes[i] = NULL;
        }
        count = 0;
    };
    void add(string name)
    {
        if (name.length())
        {
            char c = name[0];
            if(c>='a'&&c<='z')
            {
                if (subNodes[c-'a'] == NULL)
                {
                    subNodes[c-'a'] = new TrieNode();
                }
                subNodes[c-'a']->add(name.substr(1, name.length() - 1));
            }
        }
        count++;
    };
    int find(string name)
    {
        int num = 0;
        if (name.length())
        {
            char c = name[0];
            if(c>='a'&&c<='z')
            {
                if (subNodes[c-'a'] == NULL)
                {
                    return num;
                }
                else
                {
                    num = subNodes[c-'a']->find(name.substr(1, name.length() - 1));
                }
            }
        }
        else
            return count;
        return num;
    };
    /*void print()
    {
        cout<<"count  = "<<count<<endl;
        for (int i = 0; i < 26; i++)
        {
            if (subNodes[i]!=NULL)
            {
                cout<<"char = "<<char('a'+i)<<" ";
                subNodes[i]->print();
            }
        }
    }*/
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    string action, name;
    cin >> n;
    TrieNode root;
    for (int i = 0; i < n; i++)
    {
        cin >> action >> name;
        //cout<< "action is "<<action<<", name is "<<name<<endl;
        if (action.compare("add") == 0)
        {
            root.add(name);
        }
        else if (action.compare("find") == 0)
        {
            cout<<root.find(name)<<endl;
        }
    }
    //root.print();
    return 0;
}
