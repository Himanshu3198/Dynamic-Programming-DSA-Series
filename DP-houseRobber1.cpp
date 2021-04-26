
// 198. House Robber

class Solution {
public:
    int rob(vector<int>& nums) {
        
        
        int n=nums.size();
        vector<int>dp(n);
        
        if(n==1){
            return nums[0];
        }
        
        dp[n-1]=nums[n-1];
        dp[n-2]=max(nums[n-1],nums[n-2]);
        
        
        for(int i=n-3;i>=0;i--){
            
            dp[i]=max(dp[i+1],dp[i+2]+nums[i]);
        }
        
        return dp[0];
        
    }
};
