#include <iostream>

using namespace std;

class function{
public:
    function():x(0){
    }
private:
    int x;
public:
    void operator()(){
        cout<<"calling class function operator ()"<<endl;
    }
};

int main(){
    function fun;
    fun();
}
