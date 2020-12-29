// time complexity O(n)
// dp solution for friends pairing problem
#include<bits/stdc++.h>
using namespace std;

  int CountFriendPair(int n){
    
    int dp[n+1];
    dp[1]=1;
    dp[2]=2;

    for(int i=3;i<=n;i++){

        dp[i]=dp[i-1]  +  (n-1)*dp[n-2];
    }

    return dp[n];

  }

int main(){
    int n=3;
    cout<<CountFriendPair(n)<<"\n";
}