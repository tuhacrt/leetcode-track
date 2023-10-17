class MinStack {
public:
    stack<int> st = {};
    stack<vector<int>> minSt = {};

    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val < minSt.top()[0]) minSt.push({val, 1});
        else if (val == minSt.top()[0]) minSt.top()[1]++;
    }
    
    void pop() {
        if (st.top() == minSt.top()[0]) minSt.top()[1]--;
        if (minSt.top()[1] == 0) minSt.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top()[0];
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