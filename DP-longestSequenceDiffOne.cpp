
// Longest subsequence-1 

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int longestSubsequence(int n, int a[])
    {
        // code here
        
       vector<int>  dp(n+1,1);
        
        
        
        //   dp[0]=1;
        for(int i=1;i<=n;i++){
            
            for(int j=0;j<i;j++){
                
                
                if(a[i]==a[j]+1 or a[i]==a[j]-1){
                    
                    dp[i]=max(dp[i],1+dp[j]);
                }
               
                
               
            }
        }
           return *max_element(dp.begin(),dp.end());
        
        
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
} 