#include <iostream>

// c++ 4.2.1 Darwin max - 174683
// g++ 4.8.4 Linux 4.2.0 max - 261741
static int depth = 0;

void func()
{
    depth++;
    std::cout<<"depth = "<<depth<<std::endl;

    func();
}

int main()
{
    func();

    return 0;
}
