class MyStack {
public:
    queue<int> main;
    queue<int> tmp;
    MyStack() {
        
    }
    
    void push(int x) {
        while(!main.empty()){
            tmp.push(main.front());
            main.pop();
        }
        main.push(x);
        while(!tmp.empty()){
            main.push(tmp.front());
            tmp.pop();
        }
    }
    
    int pop() {
        int res=main.front();
        main.pop();
        return res;
    }
    
    int top() {
        return main.front();
    }
    
    bool empty() {
        return main.empty();
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