class Solution {
public:
    int solve(vector<int>&nums,vector<int>&multiply,int start,int end,int m,int n,int idx,vector<vector<int>>&dp){
        
        if(idx>=m || start>end || start>=n) return 0;
        if(dp[start][idx]!=INT_MAX)return dp[start][idx];
        int ans=0;
        int first=nums[start]*multiply[idx]+solve(nums,multiply,start+1,end,m,n,idx+1,dp);
        int second=nums[end]*multiply[idx]+solve(nums,multiply,start,end-1,m,n,idx+1,dp);
        ans=max(first,second);
        return  dp[start][idx]=ans;
        
    
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        
        int n=nums.size(),m=multipliers.size();
        int i=0,j=n-1;
        vector<vector<int>>dp(1002,vector<int>(10002,INT_MAX));
        return solve(nums,multipliers,i,j,m,n,0,dp);
    }
};
