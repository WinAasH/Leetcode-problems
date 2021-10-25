class MinStack {
private:
    stack<int> st;
    stack<int> minStack;
public:
    void push(int val) {
        st.push(val);
        if(minStack.empty()){
            minStack.push(val);
        }
        else{
            if(minStack.top()>=val){
                minStack.push(val);
            }
        }
    }
    
    void pop() {
        int temp= st.top();
        st.pop();
        if(minStack.top()==temp){
            minStack.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */