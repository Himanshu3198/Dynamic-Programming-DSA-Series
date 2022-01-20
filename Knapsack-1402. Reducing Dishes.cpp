class Solution {
public:
    
    
    int dp[501][501];
    
     int solve(vector<int>&nums,int idx,int j){
         
         
         if(idx>=nums.size()){
             
         
             return 0;
         }
         
         if(dp[idx][j]!=-1){
             
             return dp[idx][j];
         }
         
       
           return dp[idx][j]=max((j*nums[idx])+solve(nums,idx+1,j+1),solve(nums,idx+1,1));
         
     }

    int maxSatisfaction(vector<int>& nums) {
        
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        memset(dp,-1,sizeof(dp));
         
         return  solve(nums,0,1);
         

    }
};
