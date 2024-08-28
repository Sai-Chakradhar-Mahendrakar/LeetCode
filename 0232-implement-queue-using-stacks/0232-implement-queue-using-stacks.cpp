class MyQueue {
public:
    stack<int> main;
    stack<int> tmp;
    MyQueue() {
        
    }
    
    void push(int x) {
        main.push(x);
    }
    
    int pop() {
        if(tmp.empty()){
            while(!main.empty()){
                tmp.push(main.top());
                main.pop();
            }
        }
        int res=tmp.top();
        tmp.pop();
        return res;
    }
    
    int peek() {
        if(tmp.empty()){
            while(!main.empty()){
                tmp.push(main.top());
                main.pop();
            }
        }
        return tmp.top();
    }
    
    bool empty() {
        return main.empty() && tmp.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */