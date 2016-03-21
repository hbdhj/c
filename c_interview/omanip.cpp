#include <iostream>
using namespace std;

/*ostream& move(ostream& os, const void* data, size_t length)
{
    const int* idata= data;
    for(int i = 0; i<length; i++)
        os << idata[i];
    return os;
}*/

ostream& move(ostream& os, int x)
{
    os << "x = "<< x;
    return os;
}

main() 
{
    char str[] = "12345";
    const void* p = str;
    cout << move(3) << endl;
}