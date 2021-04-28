// BBT counter  gfg 
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  const int mod=1e9+7;
    long long int countBT(int h) { 
        // code here
        
        long long int dp[h+1];
        dp[0]=dp[1]=1;
        
        for(int i=2;i<=h;i++){
            
            dp[i]=((dp[i-1]*dp[i-2])%mod+ (dp[i-2]*dp[i-1])%mod + (dp[i-1]*dp[i-1])%mod)%mod;
        }
        
        return dp[h];
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
