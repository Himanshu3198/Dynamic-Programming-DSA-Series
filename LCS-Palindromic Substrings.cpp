class Solution {
public:
    time complexity O(n^2)
    space complexity O(n*n)
  int solve(string &s,int i,int j,vector<vector<int>>&dp){
      
      if(i>=s.size() || j<0 || i>j) return 1;
      if(dp[i][j]!=-1) return dp[i][j];
      if(i==j) return 1;
      return dp[i][j]=(s[i]==s[j])?solve(s,i+1,j-1,dp):0;
  }
    
    int countSubstrings(string s) {
        
        int n=s.size();
        int count=0;
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
          for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
              count+=solve(s,i,j,dp);
            }
        }
        return count;
       
        
    }
};
