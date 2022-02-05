


//        time comeplexity O(size(text1)*size(text2))

//  bottom-up(memoization)
class Solution {
public:

    
         int dp[1001][1001];
    
       int solve(string &text1,string &text2,int i,int j){
          
          
          
          if(i==-1 or j==-1){
              return 0;
          }
          
           if(dp[i][j]!=-1){
               
               return dp[i][j];
           }
          
          if(text1[i]==text2[j]){
              
            return dp[i][j]= 1+solve(text1,text2,i-1,j-1);
          }else{
              return dp[i][j]=max(solve(text1,text2,i,j-1),solve(text1,text2,i-1,j));
          }
          
      }
    int longestCommonSubsequence(string text1, string text2) {
        
        
              memset(dp,-1,sizeof(dp));  
       return solve(text1,text2,text1.size()-1,text2.size()-1);
        
       
    }
};
//  top-down(tabulation)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int dp[text1.size()+1][text2.size()+1];
        int res = 0;
        
        for(int i = 0; i < text1.size()+1; i++) {
            for(int j = 0; j < text2.size()+1; j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < text1.size()+1; i++) {
            for(int j = 1; j < text2.size()+1; j++) {
                char t1 = text1[i-1];
                char t2 = text2[j-1];
                if(t1 == t2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    // res = max(dp[i][j], res);
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
