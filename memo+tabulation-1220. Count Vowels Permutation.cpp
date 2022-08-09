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

// tabulation 
class Solution {
public:
     const int mod=1e9+7;
    int countVowelPermutation(int n) {
       
     
         // 0 1 2 3 4
         // a e i o u
        long long dp[n][5];
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            // presendence
            // a -> e i u
            dp[i][0]=(dp[i-1][1]+dp[i-1][2]+dp[i-1][4])%mod;
            // e-> a i
            dp[i][1]=(dp[i-1][0]+dp[i-1][2])%mod;
            // i-> e o
            dp[i][2]=(dp[i-1][1]+dp[i-1][3])%mod;
            // o->i
            dp[i][3]=(dp[i-1][2])%mod;
            // u-> i o
            dp[i][4]=(dp[i-1][2]+dp[i-1][3])%mod;
            
        }
        
        int ans=0;
        for(int i=0;i<5;i++) ans=(ans%mod+dp[n-1][i]%mod)%mod;
        return ans;
    }
};
