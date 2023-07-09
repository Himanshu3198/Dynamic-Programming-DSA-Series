class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int>&nums,int &target,int i,int j){
        if(j==(nums.size())){
           return 0;
        }
        if(dp[i][j]!=-1) return dp[i][j]; 
        int ans=INT_MIN;
        for(int k=j;k<nums.size();k++){
            int diff=(nums[k]-nums[i]);
            if(diff>=-target and diff<=target){
                ans=max(ans,1+solve(nums,target,k,k+1));
            }
        }
        return dp[i][j]=ans;
        
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=solve(nums,target,0,1);
        if(ans<0) return -1;
        return ans;
        
    }
};
