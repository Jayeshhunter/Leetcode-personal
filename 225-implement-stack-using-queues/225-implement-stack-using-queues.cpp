class MyStack {
public:
    /** Initialize your data structure here. */
stack<int> stack;
    
    /** Push element x onto stack. */
    void push(int x) {
        stack.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(empty()){
          return -1;
        }else{
          int val = top();
          stack.pop();
          return val;
        }
    }
    
    /** Get the top element. */
    int top() {
        if(empty()){
        return -1;
        }else{
        return stack.top();
          }
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
          return stack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */