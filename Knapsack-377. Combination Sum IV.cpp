class Solution {
public:
    
    unsigned int dp[201][1001];
    int memo(vector<int>&nums,int idx,int target){
        
        if(target==0) return 1;
        if(target<0) return 0;
        if(dp[idx][target]!=-1) return dp[idx][target];
        int ans=0;
        for(int i=0;i<nums.size();i++) ans+=memo(nums,i,target-nums[i]);
        return dp[idx][target]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return memo(nums,0,target);
    }
};
