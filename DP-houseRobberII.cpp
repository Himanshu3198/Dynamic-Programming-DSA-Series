// 213. House Robber II

class Solution {
public:
    int rob(vector<int>& nums) {
 
    //if the size is 1 => return nums[0]
        if(nums.size()==1){
            return nums[0];
        }
        
        //if the size is 2 => return max(nums[0], nums[1])
        if(nums.size()==2){
            return max(nums[0], nums[1]);
        }
        
        int n=nums.size();
        vector<int> dp(n);
        
        //first ans by ignoring the last element
        dp[0]=nums[0];
        dp[1]=max(nums[1], nums[0]);
        
        for(int i=2;i<n-1;i++){
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        int ans1 = dp[n-2];
        
        
        //second ans by ignoring the first element
        dp[1]=nums[1];
        dp[2]=max(nums[1], nums[2]);
        for(int i=3;i<n;i++){
            dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
        }
        
        int ans2 = dp[n-1];
        
        //final ans will be max(ans1, ans2)
        return max(ans1, ans2);
     
    }
};
