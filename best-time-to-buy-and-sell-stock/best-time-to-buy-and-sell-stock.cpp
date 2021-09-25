class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int buyP = prices[0];
    int profit = 0;
    
    
    for(int i=1 ; i<prices.size() ; i++)
    {
        if(prices[i] < buyP) buyP = prices[i];
        else profit = max(profit , prices[i]-buyP);
    }
    
    return profit;
    }
};