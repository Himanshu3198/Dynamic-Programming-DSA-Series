// 740. Delete and Earn

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
         
        int n=nums.size();
        vector<int>dp(10005,0);
             
        
        vector<int>sum(10005,0);
        
        
        for(auto x:nums){
            
              sum[x]+=x;
        }
        
       
         dp[0]=sum[0];
        dp[1]=max(sum[0],sum[1]);
        
        for(int i=2;i<10005;i++){
            
            dp[i]=max(dp[i-1],sum[i]+dp[i-2]);
        }
        
        return max(dp[10004],dp[10003]);
    
    }
};
