// Maximum sum increasing subsequence gfg||leetcode||cpp 
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n = 5;
    // cin>>n;

    int a[n] = {1, 101, 2, 3, 100};

    vector<int> dp(n);

    for (int i = 0; i < n; i++)
    {
        dp[i] = a[i];
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = i - 1; j >= 0; j--)
        {

            if (a[i] > a[j])
            {

                dp[i] = max(dp[i], a[i] + dp[j]);
            }
        }
    }
   cout<< *max_element(dp.begin(), dp.end())<<"\n";

    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
}