class Solution {
public:
    
//      the idea is to use dynamic programming based distinct subsequence
//      time complexity O(n*3)
//      space complexity O(n*3)

    long long solve(string s,string t){
  
          int n=s.size();
          int m=t.size();
          long long dp[n+1][m+1];
          memset(dp,0,sizeof(dp));
          for(int i=0;i<=n;i++) dp[i][0]=1;
          for(int i=1;i<=n;i++){
              for(int j=1;j<=m;j++){
                  
                  if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                  else dp[i][j]=dp[i-1][j];
              }
          }
         return dp[n][m];
     
    }
    long long numberOfWays(string s) {
        
      string t1="010";
      string t2="101"; 
      long long ans=solve(s,t1);
      ans+=solve(s,t2); 
      return ans;
        
        
    }
};
