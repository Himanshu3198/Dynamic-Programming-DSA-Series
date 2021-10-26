// 918. Maximum Sum Circular Subarray

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
     
          int n=nums.size();
        // if max element less than 0 than return max element
          int maxele=*max_element(nums.begin(),nums.end());
        
        if(maxele<0) return maxele;
        
        
        int arr_sum=0;
        
        int sum1=0,sum2=0,max_sum1=INT_MIN,min_sum2=INT_MAX;
        
        for(int i=0;i<n;i++){
            
            arr_sum+=nums[i];
            
            sum1+=nums[i];
            sum2+=nums[i];
            
             // find max btwn current  and max element
             max_sum1=max(max_sum1,sum1);
            
             // find min btwn current min and min element
             min_sum2=min(min_sum2,sum2);
            
            
            // if current max become less than 0 reiniatize sum1 with 0
            if(sum1<0){
                sum1=0;
            }
            // if current min become greater than 0 reiniatize sum2 with 0

            if(sum2>0){
                
                sum2=0;
            }
            
            
        }
        /* return max btwn linear max subaray and  circular max subarray by removing 
           total sum of array - min sub array
        */
        return max(max_sum1,arr_sum-min_sum2);
          
    }
};
