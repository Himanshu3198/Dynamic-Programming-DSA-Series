#include <bits/stdc++.h>
using namespace std;


        // memoization

          int dp[1001][1001];

        int solve(int n ,int W,int val[],int wt[],int idx){
            
            
            
            if(idx>=n or W==0){
                return 0;
            }
            
            if(dp[idx][W]!=-1){
                return dp[idx][W];
            }
            
            if(wt[idx]<=W){
                
                return dp[idx][W]=max(val[idx]+solve(n,W-wt[idx],val,wt,idx),solve(n,W,val,wt,idx+1));
            }else{
                
                return dp[idx][W]=solve(n,W,val,wt,idx+1);
            }
            
            
            
            
        }
    
    // Tabulation
    int Tabulation(int n,int W,  int val[],int wt[]){
         int dp[n+1][W+1];
         
         
         for(int i=0;i<=n;i++){
             
             for(int j=0;j<=W;j++){
                 
                 if(i==0 or j==0){
                     dp[i][j]=0;
                 }else if(wt[i-1]<=j){
                     
                     dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i][j-wt[i-1]]);
                 }else{
                     dp[i][j]=dp[i-1][j];
                 }
             }
         }
         
         
         for(int i=0;i<=n;i++){
             
             for(int j=0;j<=W;j++){
                 
                 cout<<dp[i][j]<<" ";
             }
             cout<<"\n";
         }
         
         return dp[n][W];

    }
 

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];

            //     memset(dp,-1,sizeof(dp));
    //   return solve(N,W,val,wt,0);

        
       
    }
    return 0;
}  
