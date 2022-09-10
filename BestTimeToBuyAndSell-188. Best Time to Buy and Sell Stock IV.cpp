class Solution {
public:
    int dp[1001][101][2];
    int memo(vector<int>&prices,int k,int toggle,int idx){
        if(idx>=prices.size() || k==0) return 0;
        if(dp[idx][k][toggle]!=-1) return dp[idx][k][toggle];
        int profit=0;
        if(toggle==0){
            int buy=memo(prices,k,1,idx+1)-prices[idx];
            int notBuy=memo(prices,k,0,idx+1);
            profit+=max(buy,notBuy);
        }else  if(toggle==1){
            int sell=prices[idx]+memo(prices,k-1,0,idx+1);
            int notSell=memo(prices,k,1,idx+1);
            profit+=max(sell,notSell);
            
        }
        return dp[idx][k][toggle]=profit;
    
    }
    int maxProfit(int k, vector<int>& prices) {
         memset(dp,-1,sizeof(dp));
         return memo(prices,k,0,0);
         
    }
};
