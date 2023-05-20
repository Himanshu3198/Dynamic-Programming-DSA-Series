class Solution {
public:
    
    int dp[100001];
    const int mod=1e9+7;
//     int dfs(int target,int zero,int one){
//         if(target<0) return 0;
//         if(target==0) return 1;
//         if(dp[target]!=-1) return dp[target];
//         int ans=0;
//         ans=(ans+dfs(target-zero,zero,one))%mod;
//         ans=(ans+dfs(target-one,zero,one))%mod;
//         return dp[target]=ans;
             
//     }
    int countGoodStrings(int low, int high, int zero, int one) {
       
      
       // memset(dp,-1,sizeof(dp));
       int ans=0;
       // for(int i=low;i<=high;i++){
       //    ans=(ans+dfs(i,zero,one))%mod;
       // }
        dp[0]=1;
        for(int i=1;i<=high;i++){
            if(i-zero>=0) dp[i]=(dp[i]+dp[i-zero])%mod;
            if(i-one>=0)  dp[i]=(dp[i]+dp[i-one])%mod;
            if(i>=low && i<=high)
            ans=(ans+dp[i])%mod;
        }
     
       return ans;
        
    }
};
