#include<bits/stdc++.h>
using namespace std;

void CountSubsequence(vector<int>& nums ,int k){

    int n=nums.size();

    int dp[k+1][n+1];
    
     memset(dp,0,sizeof(dp));

     for(int i=1;i<=k;i++){

         for(int j=1;j<=n;j++){

            dp[i][j]= dp[i][j-1];

             if(nums[j-1]<=i){
                 dp[i][j]+=dp[i/nums[j-1]][j-1]+1;
             }
         }
     }

     
     for(int i=0;i<=k;i++){
  

      for(int j=0;j<=n;j++){
          cout<<dp[i][j]<<" ";
      }
      cout<<"\n";
     }


     

     cout<<dp[k][n]<<"\n";
}
int main(){

    vector<int>nums={1,2,3,4};
    int k=4;

    CountSubsequence(nums,k);
}