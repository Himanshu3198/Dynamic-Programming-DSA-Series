//  time complexity O(n*sqrt(n))
class Solution {
public:
    
    bool isSqrt(int x){
        
        
        int y=sqrt(x);
        return y*y==x;
    }
    bool winnerSquareGame(int n) {
     
        
        
        int dp[100001];
        
        
         memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=n;i++){
            
            
            if(isSqrt(i)){
                dp[i]=1;
            }
            else{
                
                
                for(int j=1;j<=sqrt(i);j++){
                    
                    
                   if(dp[i-j*j]==0){
                       dp[i]=1;
                       break;
                   }
                }
            }
            
        }
        
        return dp[n];
    }
};
