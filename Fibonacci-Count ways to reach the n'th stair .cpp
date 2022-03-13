Count ways to reach the n'th stair 
   
    //  time complexity O(n)
    //  space complexity O(n)
    
      int dp[10001];
      int mod=1e9+7;
      int solve(int n){
          
          if(n==2){
              return 2;
          }
          if(n==1){
              return 1;
          }
          
          if(dp[n]!=-1) return dp[n];
          
          return dp[n]=(solve(n-1)+solve(n-2))%mod;
         
      }
    int countWays(int n)
    {
        // your code here
      
        memset(dp,-1,sizeof(dp));
       return solve(n);
      
        
        
        
    }
