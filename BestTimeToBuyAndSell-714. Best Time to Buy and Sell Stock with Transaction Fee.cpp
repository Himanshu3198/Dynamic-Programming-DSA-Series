// 714. Best Time to Buy and Sell Stock with Transaction Fee

class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        
        
        int n=nums.size();
        
        int bsp=-nums[0],ssp=0;
        
        
        
        for(int i=1;i<n;i++){
            
            bsp=max(bsp,ssp-nums[i]);
            
            ssp=max(ssp,bsp+nums[i]-fee);
            
           
        }
        
        return ssp;
        
        
    }
};
