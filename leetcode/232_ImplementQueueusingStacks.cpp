#include <stack>
#include <iostream>
using namespace std;
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        s.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        if (s.size() == 1)
            s.pop();
        else {
            while (s.size() > 1) {
                s2.push(s.top());
                s.pop();
            }
            s.pop();
            while (s2.size() > 0) {
                s.push(s2.top());
                s2.pop();
            }
        }
    }

    // Get the front element.
    int peek(void) {
        if (s.size() == 1) return s.top();
        while (s.size() > 1) {
            s2.push(s.top());
            s.pop();
        }
        int temp = s.top();
        s2.push(s.top());
        s.pop();
        while (s2.size() > 0) {
            s.push(s2.top());
            s2.pop();
        }
        return temp;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s.empty();
    }
private:
    stack<int> s, s2;
};

int main() {
    return 0;
}
