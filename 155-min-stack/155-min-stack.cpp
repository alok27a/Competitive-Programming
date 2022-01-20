class MinStack {
stack<int> s,ss;
public:
MinStack() {

}

void push(int val) {
    s.push(val);
    if(ss.empty() || ss.top() >= val){
        ss.push(val);
    }
}

void pop() {
    if(s.top() == ss.top()){
        ss.pop();
    }
    s.pop();
}

int top() {
    return s.top();
}

int getMin() {
    if(ss.empty()){
        return -1;
    }
    return ss.top();
}
};