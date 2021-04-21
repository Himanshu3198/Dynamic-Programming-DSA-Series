// 45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
      
        
       int n=nums.size();
        vector<int> dp(n,n-1);
        dp[n-1]=0;
        
        for(int i=n-2;i>=0;i--){
      
            int maxJumps=min(i+nums[i],n-1);
            for(int j=i+1;j<=maxJumps;j++)

                dp[i]=min(dp[i],dp[j]+1);
            
            
               for(int i=0;i<n;i++){
                cout<<dp[i]<<" ";
            }
            cout<<"\n";
          } 
        
     
        return dp[0];
    }
};
