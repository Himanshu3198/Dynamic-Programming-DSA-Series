1014. Best Sightseeing Pair

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& nums) {
        
        
          int n=nums.size();
        
           int maxi=nums[0];
          int ans=0;
        
        for(int i=1;i<n;i++){
            
            
             ans=max(ans,maxi+nums[i]-i);
              maxi=max(maxi,nums[i]+i);
        }
        
        return ans;
      
    }
};
