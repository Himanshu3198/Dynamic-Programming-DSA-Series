#include <bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<ll>freq(100001,0);
    for (int i = 0; i < n; i++){
        
        int input;
        cin>>input;
        freq[input]++;
    }
    
    ll dp[100001];
    
    memset(dp,-1,sizeof(dp));
    ll ans = INT_MIN;
    dp[0]=0;
    dp[1]=1*freq[1];
    ans = max(dp[0],dp[1]);
    
    for(int i=2;i<100001;i++){
        
        dp[i]= max(dp[i-1],dp[i-2] + freq[i]*i);
        ans = max(ans,dp[i]);
    }
    
    cout<<ans<<"\n";
    
    
    return 0;
}
