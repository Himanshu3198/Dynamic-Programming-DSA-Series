class Solution {
public:
      
    
         long long dp[100001];
    
        long long solve(vector<vector<int>>&nums,int idx){
            
            
            if(idx>=nums.size()){
                return 0;
            }
            
              if(dp[idx]!=-1){
                  return dp[idx];
              }
            
           
               
                  return dp[idx]=max(nums[idx][0]+solve(nums,idx+nums[idx][1]+1),solve(nums,idx+1));           
              
              
            
        }
    long long mostPoints(vector<vector<int>>&nums) {
        
        
         memset(dp,-1,sizeof(dp));
        
         return solve(nums,0);
   
        
        
        
    }
};
