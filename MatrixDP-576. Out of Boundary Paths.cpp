#define ll long long int
class Solution {
public:
     int dx[4]={-1,1,0,0};
     int dy[4]={0,0,-1,1};
     const int mod=1e9+7;
    int dp[51][51][51];
    bool isValid(int i,int j,int n,int m){
        if(i>=0 and i<n and j>=0 and j<m) return true;
       return false;
    }
    int dfs(int n,int m,int move,int i,int j){
        
        if(!isValid(i,j,n,m)) return 1;
        if(move<=0){
            if(!isValid(i,j,n,m)) return 1;
            return 0;
        }
        if(dp[i][j][move]!=-1) return dp[i][j][move];
        ll ans=0LL;
        for(int k=0;k<4;k++){
            
            int x=dx[k]+i;
            int y=dy[k]+j;
            
            ans+=(dfs(n,m,move-1,x,y))%mod;
        }
        return dp[i][j][move]=ans%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        memset(dp,-1,sizeof(dp));
        if(maxMove==0) return 0;
        return dfs(m,n,maxMove,startRow,startColumn);
    }
};
