class Solution {
public:
    int dp[2005][2005];
    int memo(vector<int>&nums,int i,int j,int sum,int &n){
        if(i>=j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=0;
        int a=nums[i]+nums[i+1];
        int b=nums[j]+nums[j-1];
        int c=nums[i]+nums[j];
        if(a==sum){
            res=max(res,1+memo(nums,i+2,j,sum,n));
        }
        if(b==sum){
            res=max(res,1+memo(nums,i,j-2,sum,n));
        }
        if(c==sum){
            res=max(res,1+memo(nums,i+1,j-1,sum,n));
        }
        return dp[i][j]=res;
    }
    int maxOperations(vector<int>& nums) {
        
        int res=0,n=nums.size();
        memset(dp,-1,sizeof(dp));
        res=max(res,1+memo(nums,2,n-1,nums[0]+nums[1],n));
        memset(dp,-1,sizeof(dp));
        res=max(res,1+memo(nums,0,n-3,nums[n-1]+nums[n-2],n));
        memset(dp,-1,sizeof(dp));
        res=max(res,1+memo(nums,1,n-2,nums[0]+nums[n-1],n));
        return res;
    }
};
