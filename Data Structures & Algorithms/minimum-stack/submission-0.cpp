class MinStack {
public:
    vector<int> minst; // stores all the elements of the stack
    vector<int> minval; // Stores the minimum element at each corresponding index.
    
    MinStack() {    
    }
    
    void push(int value) {
        minst.push_back(value);

        if(minval.empty())
            minval.push_back(value);
        else
            minval.push_back(min(minval.back(), value));
    }
    
    void pop() {
        minst.pop_back();
        minval.pop_back();
    }
    
    int top() {
        return minst.back();
    }
    
    int getMin() {
        return minval.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */