
// Longest alternating subsequence 
#include<bits/stdc++.h>
using namespace std;



class Solution {
	public:
	
	
	    //    int func1(vector<int>&nums,vector<int>&dp,int n){
	           
	           
	    //               int count=0;
	    //               dp[0]=1;
	                  
	    //               for(int i=1;i<n;i++){
	                      
	    //                   if(count==1){
	                          
	    //                       if(nums[i]<nums[i-1]){
	                              
	    //                           dp[i]=dp[i-1]+1;
	    //                           count=0;
	    //                       }
	    //                       else{
	    //                           dp[i]=dp[i-1];
	    //                       }
	    //                   }
	                      
	    //                   else if(count==0){
	                          
	    //                       if(nums[i]>nums[i+1]){
	                              
	    //                           dp[i]=dp[i-1]+1;
	    //                           count=1;
	    //                       }
	    //                       else{
	    //                           dp[i]=dp[i-1];
	    //                       }
	    //                   }
	                     
	                      
	    //               }
	                  
	    //            //   for(int i=0;i<n;i++){
	                      
	    //            //       cout<<dp[i]<<" ";
	    //            //   }
	    //            //   cout<<"\n";
	                  
	    //               return dp[n-1];
	    //    }
	       
	    //       int func2(vector<int>&nums,vector<int>&dp,int n){
	           
	           
	    //               int count=1;
	    //               dp[0]=1;
	                  
	    //               for(int i=1;i<n;i++){
	                      
	    //                   if(count==1){
	                          
	    //                       if(nums[i]<nums[i-1]){
	                              
	    //                           dp[i]=dp[i-1]+1;
	    //                           count=0;
	    //                       }
	    //                       else{
	    //                           dp[i]=dp[i-1];
	    //                       }
	    //                   }
	                      
	    //                   else if(count==0){
	                          
	    //                       if(nums[i]>nums[i-1]){
	                              
	    //                           dp[i]=dp[i-1]+1;
	    //                           count=1;
	    //                       }
	    //                       else{
	    //                           dp[i]=dp[i-1];
	    //                       }
	    //                   }
	                     
	                      
	    //               }
	    //            //          for(int i=0;i<n;i++){
	                      
	    //            //       cout<<dp[i]<<" ";
	    //            //   }
	    //            //   cout<<"\n";
	                  
	    //               return dp[n-1];
	    //    }
	       
	       
	       
	       
	       
		int AlternatingaMaxLength(vector<int>&nums){
		    
		    // Code here
		    
		    int n=nums.size();
		    
		      int inc=1;
		      int dec=1;
		      
		      
		      for(int i=1;i<n;i++){
		          
		          
		          if(nums[i]>nums[i-1]){
		              
		              inc=dec+1;
		          }
		          else if(nums[i]<nums[i-1]){
		              
		              
		              dec=inc+1;
		          }
		      }
		      
		      return max(inc,dec);
	
		    
		}

};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
} 