// 279. Perfect Squares

class Solution {
public:
    int numSquares(int n) {
      
           int x=sqrt(n);
   vector<int>dp(n+1,INT_MAX);

   vector<int>coins;

   for(int i=1;i<=x;i++){
       coins.push_back(i*i);
   }

   dp[0]=0;

     

   for(int i=1;i<=n;i++){
       for(int j=0;j<coins.size();j++){

           if(coins[j]<=i){


               int res=dp[i-coins[j]];
               if(res!=INT_MAX and res+1<dp[i]){
                   dp[i]=res+1;
               }

           }
       }
   }

   return dp[n];
        
    }
};
