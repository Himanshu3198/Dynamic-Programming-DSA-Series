// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        
        int i,profit=0,buy=INT_MAX;
        
        for(i=0;i<prices.size();i++){
    
             buy=min(buy,prices[i]);
            profit=max(profit,prices[i]-buy);
        }
        
        return profit;
        
    }
};
