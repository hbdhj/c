#include <stack>
#include <iostream>

using namespace std;

cclass MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        minstack.push(0x7FFFFFFF);
    }

    void push(int x) {
        if (minstack.top()>x)
            minstack.push(x);
        else
            minstack.push(minstack.top());
        stock.push(x);
    }

    void pop() {
        stock.pop();
        minstack.pop();
    }

    int top() {
        return stock.top();
    }

    int getMin() {
        return minstack.top();
    }
private:
    stack<int> stock;
    stack<int> minstack;
};

int main() {
    MinStack ms;
    ["MinStack","push","push","push","top","pop","getMin","pop","getMin","pop","push","top","getMin","push","top","getMin","pop","getMin"]
[[],[],[2147483646],[2147483647],[],[],[],[],[],[],[2147483647],[],[],[-2147483648],[],[],[],[]]
    ms.push(2147483646);
    ms.push(2147483646);
    ms.push(2147483647);
    cout<<ms.top()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    ms.pop();
    cout<<ms.getMin()<<endl;
    ms.pop();
    ms.push(2147483647);
    cout<<ms.top()<<endl;
    cout<<ms.getMin()<<endl;
    return 0;
}
