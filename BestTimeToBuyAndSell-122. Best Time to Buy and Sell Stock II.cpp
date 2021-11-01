// 122. Best Time to Buy and Sell Stock II

class Solution {
public:
    int maxProfit(vector<int>& prices) {
           
//          peak valley approach 
        
           int n=prices.size();
        
          int diff=0;
        
        for(int i=1;i<n;i++){
            
            if(prices[i]>prices[i-1]){
                
              diff+=(prices[i]-prices[i-1]);
            }
        }
                     
                     return diff;
                       
                       
        
        
               
    }
};
