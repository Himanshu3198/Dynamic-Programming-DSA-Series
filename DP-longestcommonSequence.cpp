#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string text1,string text2)
    {
        // your code here
     int dp[text1.size()+1][text2.size()+1];
        int res = 0;
        
        for(int i = 0; i < text1.size()+1; i++) {
            for(int j = 0; j < text2.size()+1; j++) {
                dp[i][j] = 0;
            }
        }
        
        for(int i = 1; i < text1.size()+1; i++) {
            for(int j = 1; j < text2.size()+1; j++) {
                char t1 = text1[i-1];
                char t2 = text2[j-1];
                if(t1 == t2) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    // res = max(dp[i][j], res);
                } else {
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }
        return dp[text1.size()][text2.size()];
        

    }
};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
