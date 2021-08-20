// 1641. Count Sorted Vowel Strings

class Solution {
public:
    int countVowelStrings(int n) {
        
        vector<int>dp(5,0);
        dp[4]=1;
        
         int sum=0;
          while(n--){
              
              for(int i=3;i>=0;i--){
                  
                  
                  dp[i]+=dp[i+1];
                  
              }
          }
    
            sum=accumulate(dp.begin(),dp.end(),0);
        return sum;
    }
};
