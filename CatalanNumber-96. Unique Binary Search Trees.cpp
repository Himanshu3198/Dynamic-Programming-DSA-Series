class Solution {
public:
    
/* this is a direct application of nth catalan number 

     c0=1,c1=1,c2=2,c3=5,c4=14..
      c4 =  c0*c3+c1*c2+ c2*c1+c3*c0  
      */
    int dp[20];
          int solve(int n){
              
                if(n<=1){
                    return 1;
                }
              if(n==2){
                  
                  return dp[n]=2;
              }
              if(dp[n]!=-1){
                  
                  return dp[n];
              }
            
              
              int res=0;
              
              for(int i=0;i<n;i++){
                  
                  res+=(solve(i)*solve(n-i-1));
                  
              }
              
              return dp[n]=res;
              
          }
    int numTrees(int n) {
     
    
       memset(dp, -1, sizeof(dp));
        
            return solve(n);
    }
};
