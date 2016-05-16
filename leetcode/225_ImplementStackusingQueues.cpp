class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue<int> bak;
        while(que.size()>1) {
            bak.push(que.front());
            que.pop();
        }
        int ret = que.front();
        que.pop();
        que = bak;
    }

    // Get the top element.
    int top() {
        return que.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
private:
    queue<int> que;
};
