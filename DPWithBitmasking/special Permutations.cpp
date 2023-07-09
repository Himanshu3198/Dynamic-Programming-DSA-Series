class Solution {
public:
    int mod=1e9+7;
    int dp[15][1<<14];
    int solve(vector<int>&nums,int mask,int idx){
        if(mask==0){
            return 1;
        }
        if(dp[idx][mask]!=-1) return dp[idx][mask];
        long long  count=0;
        for(int i=0;i<nums.size();i++){
            if((mask&(1<<i))){
                
                if(i==0 || (nums[idx]%nums[i]==0) || (nums[i]%nums[idx]==0))
                count+=(solve(nums,mask^(1<<i),i))%mod;
            }  
        }
        return dp[idx][mask]=count%mod;
    }
    int specialPerm(vector<int>& nums) {
        
        int n=nums.size();
        int mask=(1<<n)-1;
        memset(dp,-1,sizeof(dp));
        return solve(nums,mask,0);
    }
};
