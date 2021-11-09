class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        
            int n=matrix.size();
            int m=matrix[0].size();
        
         vector<vector<int> > dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
      
        
        for(int i=1;i<dp.size();i++){
            
            for(int j=1;j<matrix[0].size()+1;j++){
                
                
                dp[i][j]=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
        
 
        
         vector<vector<int>>res(n,vector<int>(m,0));
        
        
        
        for(int i=0;i<matrix.size();i++){
            
            for(int j=0;j<matrix[i].size();j++){
                
                
                   int n=matrix.size();
                   int m=matrix[i].size();
                int r1=max(0,i-k)+1;
                int c1=max(0,j-k)+1;
                int r2=min(i+k+1,n);
                int c2=min(j+k+1,m);
                
                
                res[i][j]=dp[r2][c2]+dp[r1-1][c1-1]-dp[r1-1][c2]-dp[r2][c1-1];
                                                    
            }
        }
        
        return res;
    }
    
    
    
    
    
    
};
