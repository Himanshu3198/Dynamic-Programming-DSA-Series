#define ll long long int
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
         int n=nums.size();
        
          if(n<3) return 0;
        vector<map<ll,ll>>dp(n);
        
          int ans=0;
        for(int i=0;i<n;i++){
            
            
            for(int j=0;j<i;j++){
                
                 ll diff= (ll)nums[i]-(ll)nums[j];
                
               dp[i][diff]++;
                
                if(dp[j].find(diff)!=dp[j].end()){
                    
                    dp[i][diff]+=dp[j][diff];
                    ans+=dp[j][diff];
                }
            }
        }
        
        return ans;
    }
};
