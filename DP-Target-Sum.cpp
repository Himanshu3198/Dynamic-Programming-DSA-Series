// 494. Target Sum

class Solution {
public:
    
    /* in this problem we need to make target sum by putting +1 -1 or something kind
    +1 +2 +3 -1 -2 -4  we add divided it like this all positive one side and all negative
    another side than target sum will be (all positive)-(all negative)=target 
     we can simply it on number line  set 1 sum as s1 set2 s2 sum will (sum-s1) so
     as we know that s1-s2=target  and
     s1-(sum-s1)=target
      2s1=target+sum
      s1=(target+sum)/2
      s2=sum-s1
        Now we have figure out the sum the only we have to do is to partition the array the in such way that both elements sum will have same target*/
    int countSubset(vector<int>& nums, int sum)
    {
        int sz = nums.size();
        int dp[sz+1][sum+1] ;
        
        for(int i=0; i<=sz; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(i==0){ dp[i][j] = 0;}
                if(j==0){ dp[i][j] = 1;}
            }
        }
        for(int i=1; i<=sz; i++)
        {
            for(int j=0; j<=sum; j++)
            {
                if(nums[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[sz][sum];
    }
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int totalSum = 0;
        
        for(int i : nums){ totalSum += i ;}
        
        bool ifOddSum = (totalSum + target)%2 != 0 ? true : false ; 
        
        if( totalSum<target || ifOddSum){return 0;}
        
        int subsetSum = (target + totalSum)/2 ;
        
        return countSubset(nums, subsetSum);
    }
};
