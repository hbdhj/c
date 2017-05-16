#include <iostream>
#include <typeinfo>

struct A { double x; };
const A* a = new A{0};

decltype(a->x) y;       // type of y is double (declared type)
decltype((a->x)) z = y; // type of z is const double& (lvalue expression)

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u); // return type depends on template parameters

int main()
{
    int i = 33;
    decltype(i) j = i * 2;

    std::cout << "i = " << i << ", " << "type of i: " << typeid(i).name() << '\n'
              << "j = " << j << ", " << "type of j: " << typeid(j).name() << '\n';

    auto f = [](int a, int b) -> int
    {
        return a * b;
    };

    decltype(f) g = f; // the type of a lambda function is unique and unnamed
    std::cout << "type of f: " << typeid(f).name() << ", type of g: " << typeid(g).name() << "\n";
    i = f(2, 2);
    j = g(3, 3);

    std::cout << "i = " << i << ", "
              << "j = " << j << '\n';

    return 0;
}
