      
//  time & space complexiy O(n*m)
int dp[1001][1001];
      
      int lcs(string s1, string s2, int n, int m,int count){
             if(n==0 or m==0){
              return count;
          }
          if(dp[n][m]!=-1){
              return dp[n][m];
          }
          
          if(s1[n]==s2[m]){
              
              return count=lcs(s1,s2,n-1,m-1,count+1);
          }else{
              
              return count=max({count,lcs(s1,s2,n-1,m,0) ,lcs(s1,s2,n,m-1,0)});
          }
          
          return dp[n][m]=count;
          
      }
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
         memset(dp,0,sizeof(dp));
        // return lcs(S1,S2,n-1,m-1,0);
        
        int maxResult=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(S1[i-1]==S2[j-1]){
                    
                    dp[i][j]=1+dp[i-1][j-1];
                }
                
                maxResult=max(maxResult,dp[i][j]);
            }
        }
        
        return maxResult;
        
    }
