// 357. Count Numbers with Unique Digits

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0) return 1;
        if(n==1) return 10;
        
         vector<int>dp(n+1,0);
        
            dp[0]=1;
            dp[1]=10;
        
        for(int i=2;i<=n;i++){
            
            int nums=dp[i-1]-dp[i-2];
            
            dp[i]=nums*(10-i+1)+dp[i-1];
            
       
        }
        
        return dp[n];
        
        
    }
};
