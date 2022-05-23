//    memoization
class Solution {
public:
      static const auto _____ = []()
{
    // fast IO code : this I understand
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}();
class Solution {
public:
    
    vector<int>freq(string &s){
          vector<int>v(2,0);
          for(auto &it:s) v[it-'0']++;
          return v;
    }
    int solve(vector<string>& s,int zeros,int ones,int idx,vector<vector<vector<int>>>&dp){
        
         if(idx>=s.size() || (zeros+ones==0)) return 0;
         if(dp[idx][zeros][ones]!=-1) return dp[idx][zeros][ones];
         vector<int>count=freq(s[idx]);
         int pick=0,notPick=0;
         if(zeros>=count[0] && ones>=count[1]){
             pick=1+solve(s,zeros-count[0],ones-count[1],idx+1,dp);   
         }
         notPick=solve(s,zeros,ones,idx+1,dp);
         return dp[idx][zeros][ones]=max(pick,notPick);

    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
     
           vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
           return solve(strs,m,n,0,dp);
    }
};


//  tabular dp

class Solution {
public:
       vector<int> count(string s){
           
           vector<int>freq(2,0);
           
           for(auto it:s){
               
               freq[it-'0']++;
           }
           
           return freq;
           
           
       }
    

        
       
    int findMaxForm(vector<string>& s, int m, int n) {
        
                 int size=s.size();
                  
                 int dp[m+1][n+1];
              memset(dp,0,sizeof(dp));
        
        
           for(int i=0;i<size;i++){
               
               
               vector<int>freq=count(s[i]);
               for(int j=m;j>=freq[0];j--){
                   
                   
                   for(int k=n;k>=freq[1];k--){
                       
                       dp[j][k]=max( dp[j-freq[0]][k-freq[1]]+1,dp[j][k]);
                   }
               }
           }
        
        
     
        
        return dp[m][n];
          
        
        
            
         
    }
};
