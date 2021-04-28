// Knapsack with Duplicate Items 


#include <bits/stdc++.h>
using namespace std;
// User function Template for C++

class Solution{
public:
    int knapSack(int n, int W, int val[], int wt[])
    {
        // code here
        int dp[W+1];
        memset(dp,0,sizeof(dp));
        
        
        
        
        for(int i=1;i<=W;i++){
            
            for(int j=0;j<n;j++){
                
                
                if(wt[j]<=i){
                    
                   
                
            
                    dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
                }
            }
        }
      
        return dp[W];
    }
};



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
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  