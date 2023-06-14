class Solution {
public:
//     the ideas is to represent all possible subsequence of array in the form bits maximum is 1<<(size of arr)-1 and do brute force
    unordered_map<int,int>dp;
    int solve(vector<int>&nums,int idx,int mask){
        if(idx==0) return 0;
        if(dp.count(mask)) return dp[mask];
        int ans=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                
                if(i!=j){
                    
                    if((mask&(1<<i)) && (mask&(1<<j))){
                        ans=max(ans,idx*__gcd(nums[i],nums[j])+solve(nums,idx-1,mask^(1<<i)^(1<<j)));
                    }
                }
            }
        }
        return dp[mask]=ans;
    }
    int maxScore(vector<int>& nums) {
        // memset(dp,-1,sizeof(dp));
        int n=nums.size();
        int mask=(1<<n)-1;
        return solve(nums,n/2,mask); 
    }
};
