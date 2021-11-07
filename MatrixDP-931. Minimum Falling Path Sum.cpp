// 931. Minimum Falling Path Sum

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        
         int n=mat.size();
         int m=mat[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        
        for(int i=0;i<m;i++){
            
            
            dp[0][i]=mat[0][i];
        }
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                
                if(j==0){
                    
                    dp[i][j]= mat[i][j]+min(dp[i-1][j],dp[i-1][j+1]);
                    
                }
                else if(j==m-1){
                    dp[i][j]=mat[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    
                    dp[i][j]=mat[i][j]+min({dp[i-1][j],dp[i-1][j-1],dp[i-1][j+1]});
                }
            }
        }
        
        for( auto it:dp){
            
            for(auto it1:it){
                
                cout<<it1<<" ";
            }
            cout<<"\n";
        }
      int mini=INT_MAX;
        for(int i=0;i<m;i++)
        {
            mini = min(dp[n-1][i],mini);
        }
        return mini;
        

    }
};
