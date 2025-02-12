class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = INT_MIN;
        int mini = INT_MAX;
        
        for(auto i : prices)
        {
            mini = min(mini,i);
            profit = max(profit, i - mini);
        }
        return profit;
    }
};