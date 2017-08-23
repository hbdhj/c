#include <iostream>

using namespace std;

class myclass{
public:
    void print(){
        cout<<"class myclass method print"<<endl;
    }
};

template<typename T>
class Test{
public:
    T t;
    void run(){
        t.print();
    }
};

int main(){
    myclass myc;
    Test<myclass> test;
    test.t = myc;
    test.run();
}
