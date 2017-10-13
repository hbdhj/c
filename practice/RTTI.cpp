// please use g++

#include <iostream>
#include <typeinfo>

using namespace std;

int main() 
{
    int i;
    cout << "i is a "<<typeid(i).name()<<endl;
    return 0;
}
