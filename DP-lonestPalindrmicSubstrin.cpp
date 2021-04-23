#include<bits/stdc++.h>
using namespace std;

string longestPalin (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


string longestPalin (string s)
{
    // your code here
    
            int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        int maxLen=1;
        
        //for substr of length 1
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        
        //for substr of length 2
        int start=0;
        for(int i=0;i<n-1;i++)
        {
           if(s[i]==s[i+1]) 
           {
               dp[i][i+1]=1;
               start=i;
               maxLen=2;
           }
        }
        
        //sustr of length _k_
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(dp[i+1][j-1]==1 && s[i]==s[j])
                {
                    dp[i][j]=1;
                    if(k>maxLen)
                    {
                        start=i;
                        maxLen=k;
                    }
                }
            }
        }
        
        return s.substr(start,maxLen);
  
        
}