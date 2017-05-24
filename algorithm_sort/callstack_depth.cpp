#include <iostream>

// c++ 4.2.1 Darwin
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
