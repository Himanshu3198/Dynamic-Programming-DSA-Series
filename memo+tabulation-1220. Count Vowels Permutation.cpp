class Solution {
public:
     const int mod=1e9+7;
     int dp[20001][5];
     int dfs(vector<vector<int>>&graph,int node,int n){
        if(n==0)
           return 1;
        if(dp[n][node]!=-1) return dp[n][node];
        int ans=0;
        for(auto it:graph[node]){
            ans= (ans%mod+(dfs(graph,it,n-1))%mod)%mod;
        }
        return dp[n][node]=ans;
    }
    int countVowelPermutation(int n) {
       
      vector<vector<int>>graph={{1},{0,2},{0,1,3,4},{2,4},{0}};
      int result=0;
      memset(dp,-1,sizeof(dp));
      for(int i=0;i<5;i++){
         result=(result%mod+dfs(graph,i,n-1)%mod)%mod;
      }
        return result;
    }
};
