// memoization solution
class Solution {
public:
     
      int dp[1000][1000];
    int helper(string &s,int idx1, int idx2,string &t){

        
           if(idx2==t.length()){
            return 1;
        }
       if(idx1==s.length()){
         
       
           return 0;
       }
        
      
        
        if(dp[idx1][idx2]!=-1){
            return dp[idx1][idx2];
        }
        
        int res=0;
        if(s[idx1]==t[idx2]){
            
            res+=helper(s,idx1+1,idx2+1,t)+helper(s,idx1+1,idx2,t);
        }else{
            
            res+=helper(s,idx1+1,idx2,t);
        }
      
        
        
         return dp[idx1][idx2]=res;



}
    
    
    int numDistinct(string s, string t) {
        
         
         memset(dp,-1,sizeof(dp));
         return helper(s,0,0,t);
    
            
        
        
        
    }
};

// bottom up dp

   
    int numDistinct(string s, string t) {
        
         

          const int mod=1e9+7;
        
          int n=s.length(),m=t.length();
        
          int dp[n+1][m+1];
           memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        
        for(int i=1;i<=n;i++){
            
            for(int j=1;j<=m;j++){
                
                if(s[i-1]==t[j-1]) {
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                }
                else {
                    dp[i][j]=dp[i-1][j]; 
                }
                   
            }
        }
        
        return dp[n][m];
          
        
        
        
    }
};
