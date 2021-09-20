// 1137. N-th Tribonacci Number

class Solution {
public:
    
        int solve(vector<int>&dp,int n){
            
                 if(dp[n]!=-1){
                     return dp[n];
                 }
            
            
              int res=solve(dp,n-1)+solve(dp,n-2)+solve(dp,n-3);
            
               dp[n]=res;
              return res;
            
        }
    int tribonacci(int n) {
         
      
        vector<int>dp(38,-1);
        
         dp[0]=0;
         dp[1]=1;
          dp[2]=1;
   
         
          return solve(dp,n);
        }
};
