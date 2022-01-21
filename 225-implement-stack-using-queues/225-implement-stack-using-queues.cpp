class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        
    }
//     q1: {10,20,30}
//     q2: {}
    void push(int x) {
        while(q1.empty()==false)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(q2.empty()==false)
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    
    int pop() {
        int a=q1.front();
        q1.pop();
        return a;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        if(q1.empty()==true) return true;
        return false;
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