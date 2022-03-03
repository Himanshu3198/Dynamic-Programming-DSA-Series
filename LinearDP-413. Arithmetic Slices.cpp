413. Arithmetic Slices


class Solution {
public:
    
      /* in this problem we need not check ap for more than 3 length if the last three 
      contiguous  sequence are in ap  then result of ap of length >3 is stored in dp array
       we need to add just +1 in it*/
    int numberOfArithmeticSlices(vector<int>& nums) {
        
           int n=nums.size();
        
          if(n<3) return 0;
          vector<int>dp(n,0);
        
           int ans=0;
        for(int i=2;i<n;i++){
            
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                
                dp[i]=1+dp[i-1];
                ans+=dp[i];
            }    
       }
        
        return ans;
        
    }
};
