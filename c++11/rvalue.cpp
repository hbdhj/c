#include <iostream>       // std::cout

class Intvec
{
public:
    explicit Intvec(size_t num = 0)
        : m_size(num), m_data(new int[m_size])
    {
        log("constructor");
    }

    ~Intvec()
    {
        log("destructor");
        if (m_data) {
            delete[] m_data;
            m_data = 0;
        }
    }

    Intvec(const Intvec& other)
        : m_size(other.m_size), m_data(new int[m_size])
    {
        log("copy constructor");
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = other.m_data[i];
    }
    // C++ 98
    Intvec& operator=(const Intvec& other)
    {
        log("copy assignment operator");
        Intvec tmp(other);
        std::swap(m_size, tmp.m_size);
        std::swap(m_data, tmp.m_data);
        return *this;
    }
    // C++ 11
    Intvec& operator=(Intvec&& other)
    {
        log("move assignment operator");
        std::swap(m_size, other.m_size);
        std::swap(m_data, other.m_data);
        return *this;
    }
private:
    void log(const char* msg)
    {
        std::cout << "[" << this << "] " << msg << "\n";
    }

    size_t m_size;
    int* m_data;
};

int main()
{
    Intvec v1(20);
    Intvec v2;

    std::cout << "assigning lvalue...\n";
    v2 = v1;
    std::cout << "ended assigning lvalue...\n";

    std::cout << "assigning rvalue...\n";
    v2 = Intvec(33);
    std::cout << "ended assigning rvalue...\n";

    return 0;
}
