#include <iostream>

using namespace std;

template <typename T> 
void function(T &t){
    t.print();
}

class myclass{
public:
    void print(){
        cout<<"class myclass method print"<<endl;
    }
};

int main(){
    myclass myc;
    function(myc);
}
