class Solution {
public:
    void push(int value) {
        if(temp.empty())
            minofstack.push(value);
        if(value < minofstack.top())
            minofstack.push(value);
        temp.push(value);
    }
    void pop() {
        if(temp.top()== minofstack.top())
            minofstack.pop();
        temp.pop();
    }
    int top() {
        return temp.top();
    }
    int min() {
        return minofstack.top();
    }
private:
    stack<int> temp;
    stack<int> minofstack;
};