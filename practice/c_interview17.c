#include <iostream>

using namespace std;

int main()
{
    int x = 2, y, z;
    cout << "x = " << x << ", y = " << y << ", z = " << z <<endl;
    x *= (y=z=5);
    cout << "x = " << x << ", y = " << y << ", z = " << z <<endl;
    z =3;
    x += (y & z); // bit and 
    cout << "x = " << x << ", y = " << y << ", z = " << z <<endl;
    x += (y && z); // and
    cout << "x = " << x << ", y = " << y << ", z = " << z <<endl;
    cout<< 'abc' << "def" <<endl; // output is 6382179def warning: multi-character character constant [-Wmultichar]
    return 0;
}
