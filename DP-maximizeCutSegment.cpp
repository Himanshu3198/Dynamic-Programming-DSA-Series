  
//  time complexity O(n*m)
 int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        
        vector<int>coin={x,y,z};
     
            sort(coin.begin(),coin.end());
           int dp[n+1];
         

         for(int i=0;i<=n;i++){
             
             dp[i]=INT_MIN;
         }
         
         dp[0]=0;
         
         
         
         for(int i=1;i<=n;i++){
             
             for(int x:coin){
                 if(x<=i)
                  dp[i]=max(dp[i],(dp[i-x]+1));
             }
         }
         
        if(dp[n]<0){
            return 0;
        }
        
        return dp[n];
         
      
     
        
      
      
    }
