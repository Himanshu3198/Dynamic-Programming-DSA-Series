70. Climbing Stairs


class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            
            dp[i]=dp[i-1]+dp[i-2];
        }
         return dp[n];
    
    }
};

// memoization
class Solution {
public:
          int solve(vector<int>&dp,int n){
              
              
              if(dp[n]!=-1){
                  return dp[n];
              }
              
          if(n==1 or n==0){
              dp[n]=1;
            return 1;
              }
               
        int ans=solve(dp,n-1)+solve(dp,n-2);
              
              dp[n]=ans;
              
              return ans;
        }
    int climbStairs(int n) {
          
          vector<int>dp(46,-1);
        
         return  solve(dp,n);
    
    }
};
