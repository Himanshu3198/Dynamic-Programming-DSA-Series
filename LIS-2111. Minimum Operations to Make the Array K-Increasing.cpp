class Solution {
public:
    
       int LIS(vector<int>&nums){
           
            int n=nums.size();
           
           vector<int>v;
           
            v.push_back(nums[0]);
           
           for(int i=1;i<n;i++){
               
               if(nums[i]>=v.back()){
                   v.push_back(nums[i]);
               }else{
                   
                   int idx=upper_bound(v.begin(),v.end(),nums[i])-v.begin();
                   
                   v[idx]=nums[i];
               }
           }
           
           return v.size();
           
           
       }
    int kIncreasing(vector<int>& arr, int k) {
        
        int res=0;
        for(int i=0;i<k;i++){
            vector<int>temp;
            for(int j=i;j<arr.size();j+=k){
                temp.push_back(arr[j]);
            }
            
            
            res+=temp.size()-LIS(temp);
        }
        
        return res;
        
         
    }
};
