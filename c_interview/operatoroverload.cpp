#include <iostream>

class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double real=0, double imag=0)
    {
        this->real=real;
        this->imag=imag;
    }
    friend Complex operator+(Complex com1, Complex com2);
    void showSum();
};


Complex operator+(Complex com1,Complex com2)
{
    return Complex(com1.real+com2.real, com1.imag+com2.imag);
}

void Complex::showSum()
{
    std::cout<<real;
    if(imag>0)
        std::cout<<"+";
    if(imag!=0)
        std::cout<<imag<<"i"<<std::endl;
}

int main()
{
    Complex com1(10,10), com2(20,-20), sum;
    sum=com1+com2;
    sum.showSum();

    return 0;
}
