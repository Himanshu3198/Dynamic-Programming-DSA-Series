45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int n=nums.size();
         vector<int>dp(n,INT_MAX);
        
        
        dp[0]=0;
      
        
        
        for(int i=0;i<n;i++){
            
            
            for(int j=i+1;j<=min(n-1,nums[i]+i);j++){
                
                
                dp[j]=min(dp[j],dp[i]+1);
            }
           
            
        
        }
        
        return dp[n-1];
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
