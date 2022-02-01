class Solution {
public:
    int maxProfit(vector<int>& nums) {
        
        
      int  minbuy=nums[0],res=0,n=nums.size();
        
        
        
        for(int i=1;i<n;i++){
            
            int curr=nums[i]-minbuy;
            if(curr<0){
                
                minbuy=nums[i];
            }else{
                
                res=max(res,curr);
            }
        }
        
        return res;
    }
};
