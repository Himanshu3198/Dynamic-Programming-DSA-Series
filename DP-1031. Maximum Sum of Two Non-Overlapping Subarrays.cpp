// 1031. Maximum Sum of Two Non-Overlapping Subarrays

class Solution {
public:
    
    
       int solve(vector<int>&nums,int x,int y){
           
           
             int n=nums.size();
              
              vector<int>dp1(n,0),dp2(n,0);
           
           
              int sum=0;
           
                for(int i=0;i<n;i++){
                    
                    if(i<x){
                        
                        sum+=nums[i];
                        dp1[i]=sum;
                    }
                    
                    else{
                        
                        sum+=(nums[i]-nums[i-x]);
                         
                        dp1[i]=max(dp1[i-1],sum);
                    }
                }
               cout<< "dp1-> ";
              for(auto it:dp1){
                  cout<<it<<" ";
              }
             cout<<"\n";
             sum=0;
              cout<< "dp2-> ";
              for(int i=n-1;i>=0;i--){
                  
                  if(i+y>=n){
                      
                      sum+=nums[i];
                      dp2[i]=sum;
                  }
                  else{
                       sum+=(nums[i]-nums[i+y]);
                      dp2[i]=max(dp2[i+1],sum);
                  }
              }
                for(auto it:dp2){
                  cout<<it<<" ";
              }
             cout<<"\n";
             
            int res=0;
           
            for(int i=x-1;i<n-y;i++){
                 
                res=max(res,dp1[i]+dp2[i+1]);
                
            }
           
           return res;
       }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstlen, int secondlen) {
        
        
             return(max(solve(nums,firstlen,secondlen),solve(nums,secondlen,firstlen)));
        
    }
};
