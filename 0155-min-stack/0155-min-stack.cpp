class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        stk.push(val);
        
        if(minStk.empty() or val<minStk.top().first){
            minStk.push({val,1});
        }else if(val==minStk.top().first){
            minStk.top().second++;
        }
    }
    
    void pop() {
        if(stk.top() == minStk.top().first){
            minStk.top().second--;
            if(minStk.top().second==0){
                minStk.pop();
            }
        }
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top().first;
    }
    private:
        stack<int> stk;
        stack<pair<int, int>> minStk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */