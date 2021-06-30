45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
       int n=nums.size();
        vector<int> dp(n,n-1);
        dp[n-1]=0;
        
        for(int i=n-2;i>=0;i--){
      
            int maxJumps=min(i+nums[i],n-1);
            for(int j=i+1;j<=maxJumps;j++)

                dp[i]=min(dp[i],dp[j]+1);
            
            
          
          } 
        
     
        return dp[0];
    }
};
 
              //  method 2

         int curend=0,maxfar=0,count=0;
        
        for(int i=0;i<nums.size()-1;i++){
            
            
            maxfar=max(maxfar,i+nums[i]);
            if(i==curend){
                count++;
                curend=maxfar;
            }
        }
        return count;
