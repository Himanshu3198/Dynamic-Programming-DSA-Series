Jump Game 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int jump=nums[0];
        int n=nums.size();
        
        for(int i=1;i<nums.size();i++){
           
            
            if(jump--){
                
                jump=max(jump,nums[i]);
                
            }
            
            if(jump<=0 and i!=n-1){
                return false;
            }
        }
        
        return true;
    }
};
