/*

C++ Class Templates

Sample Input

3
30 40 45 10 10
40 40 40 10 10
50 20 30 10 10

Sample Output

1

*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
template <class T>
class AddElements  {
    T element;
public:
    AddElements (T arg) {element=arg;}
    T add (T arg) { return element+arg;}
    T concatenate (T arg) { return element+arg;}
};

int main () {
  int n,i;
  cin >> n;
  for(i=0;i<n;i++) {
    string type;
    cin >> type;
    if(type=="float") {
        double element1,element2;
        cin >> element1 >> element2;
        AddElements<double> myfloat (element1);
        cout << myfloat.add(element2) << endl;
    }
    else if(type == "int") {
        int element1, element2;
        cin >> element1 >> element2;
        AddElements<int> myint (element1);
        cout << myint.add(element2) << endl;
    }
    else if(type == "string") {
        string element1, element2;
        cin >> element1 >> element2;
        AddElements<string> mystring (element1);
        cout << mystring.concatenate(element2) << endl;
    }
  }
  return 0;
}