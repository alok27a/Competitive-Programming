class StockSpanner {
public:
    vector<int> stocks;
    stack<int> s;
    int i=-1;
    
    StockSpanner() {
    
    }
    
    int next(int price) {
        i++;
        stocks.push_back(price);
        while(s.empty()==false && stocks[s.top()]<=price)
            s.pop();
        int span=s.empty()?i+1:i-s.top();
        s.push(i);
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */