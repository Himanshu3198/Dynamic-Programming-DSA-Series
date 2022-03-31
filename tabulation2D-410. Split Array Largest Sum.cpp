  /*
    
    
    approach: the is to make all possible split  with help of dp and prefix sum
    time complexity O(n*n*m)
    space complexity O(n*m)
    */
    



class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
     
    
        int n=nums.size();
        for(int i=1;i<n;i++) nums[i]+=nums[i-1];
        
        vector<vector<int>>dp(n,vector<int>(m+1,INT_MAX));
        for(int i=0;i<n;i++){
            dp[i][1]=nums[i];
        }
        
        dp[0][0]=0;
        
        for(int i=0;i<n;i++){
            
            for(int j=2;j<=m;j++){
                
                for(int k=0;k<i;k++){
                    
                    dp[i][j]=min(dp[i][j],max(dp[k][j-1],nums[i]-nums[k]));
                }
            }
        }
        
        return dp[n-1][m];
    }
};
