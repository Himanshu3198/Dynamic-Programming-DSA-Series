// 343. Integer Break

class Solution {
public:
    
    
    
      /* the idea is to  if we have number n   and we have to split it atleast two part  such that
        product will be maximum  it can do like this n*func(n-1) or k*func(n-k) or k*func(i-k)
        
         where   i>=1 and i<=n,  k>=1 and k<=i;
         
         but we need to maximize the product so it cannot be a complete recurrance formula
          
          suppose we need to split 5  like 
          2*func(5-2)
          2*func(3)
           
           func(3)=2;
           
           func(5)=2*2=4
           but we can do instead of this 2*(5-3)=2*3=6 which is max product
           
           so our final recurrance formula will be  for dp[i]=max(dp[i],k*max(dp[i-k],i-k);
           
          
           
         
            */
    int integerBreak(int n) {
        
     
          vector<int>dp(n+1,INT_MIN);
        
        dp[0]=1;
        dp[1]=1;
        
        for(int i=2;i<=n;i++){
            
            for(int k=1;k<i;k++){
                
                
                
                dp[i]=max(dp[i],k*max(dp[i-k],i-k));
            }
        }
        
        return dp[n];
        
    
    }
};
