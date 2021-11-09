class NumMatrix {
public:
       vector<vector<int>>dp;
    NumMatrix(vector<vector<int>>& matrix) {
        dp.resize(matrix.size()+1,vector<int>(matrix[0].size()+1,0));
        
        
       for(int i=1;i<dp.size();i++){
            
            for(int j=1;j<dp[i].size();j++){
                
                
                dp[i][j]=matrix[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
            }
        }
      
        
        
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
     
        
        
         row1++,col1++,row2++,col2++;
        
      
              
        
           int  ans=dp[row2][col2]+dp[row1-1][col1-1]-dp[row1-1][col2]-dp[row2][col1-1];        
        return ans;
           
        
             
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
