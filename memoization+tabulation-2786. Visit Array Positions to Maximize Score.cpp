class Solution {
public:
   
    long long Max(long long &a,long long &b){
        if(a>b) return a;
        return b;
    }
    long long dp[100001][2];
    long long solve(vector<int>&nums,int x,int idx,long long prev,int parity){
      
        if(idx==nums.size()) return 0;
        if(dp[idx][parity]!=-1) return dp[idx][parity];
        long long ans=0;
        int newParity=nums[idx]%2,fine=0;
        
            if(newParity!=parity)
                fine=x;
    
            long long op1=nums[idx]-fine+solve(nums,x,idx+1,nums[idx],newParity);
            long long op2=solve(nums,x,idx+1,prev,parity);
            ans=Max(op1,op2);
            return dp[idx][parity]=ans;
         
    }
    long long maxScore(vector<int>& nums, int x) {
        
        memset(dp,-1,sizeof(dp));
        int parity=nums[0]%2;
        return solve(nums,x,1,nums[0],parity)+nums[0];
       
    }
};

// *******tabulation******************************
long long maxScore(vector<int>& nums, int x) {
        
        memset(dp,0,sizeof(dp));
        int parity=nums[0]%2;
        // return solve(nums,x,1,nums[0],parity)+nums[0];
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            for(int parity=0;parity<=1;parity++){
                long long ans=0;
                int newParity=nums[i]%2,fine=0;
                if(newParity!=parity)
                  fine=x;
                long long op1=nums[i]-fine+dp[i+1][newParity];
                long long op2=dp[i+1][parity];
                ans=Max(op1,op2);
                dp[i][parity]=ans;
            }
            
        }
        return dp[0][parity];
        
       
    }
};
