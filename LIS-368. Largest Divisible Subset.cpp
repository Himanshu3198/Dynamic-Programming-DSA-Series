class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
//          the idea is to use lis dp
           int n=nums.size();
          vector<int>dp(n,1);
          int maxEle=1;
        
          if(n==1) return {nums[0]};
        
          sort(nums.begin(),nums.end());
            for(int i=1;i<n;i++){
                
                for(int j=0;j<i;j++){
                    
                    if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i]){
                        
                        dp[i]=(1+dp[j]);
                        maxEle=max(maxEle,dp[i]);
                    }
                }
            }
        
             for(auto it:dp) cout<<it<<" ";
              int prev=-1;
          vector<int>res;
           for(int i=n-1;i>=0;i--){
               
               if(maxEle==dp[i] and (prev==-1 or prev%nums[i]==0)){
                   maxEle--;
                   res.push_back(nums[i]);
                   prev=nums[i];
                       
               }  
           }
        
        return res;
    }
};
