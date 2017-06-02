#include <iostream>
using namespace std;
class A {
public:
    A(){}
};

void foo() {
    throw new A;
}

int main() {
    try {
        foo();
    } catch (A& x) {
        cout<<"here"<<endl;
    }
}
