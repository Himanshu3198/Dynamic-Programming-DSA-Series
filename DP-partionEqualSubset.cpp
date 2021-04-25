class Solution {
    

 
public:
    
       bool canPartition(vector<int>& nums) {
       
         int n=nums.size();
            int sum=0;
           for(int x:nums){
               
               sum+=x;
           }
           
           if(sum%2!=0){
               return false;
           }
           
            sum/=2;
           
           
           int dp[n+1][sum+1];
           
            memset(dp,0,sizeof(dp));
           

           dp[0][0]=1;
           
           for(int i=1;i<=n;i++){
                 for(int j=1;j<=sum;j++){
                     
                 
                     
                      if(nums[i-1]>j){
                              dp[i][j]=dp[i-1][j];
                          
                          
                      }
                     
                     else{
                         dp[i][j]=max(dp[i-1][j],dp[i-1][j-nums[i-1]]);
                     }
                 }
           }
           
           return dp[n][sum];
       }

    
   
};
