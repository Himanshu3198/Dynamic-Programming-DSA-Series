#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];
//  recursive +memoization
int solve(int W, int wt[], int val[], int n, int idx)
{

    if (idx >= n)
    {

        return 0;
    }

    if (W == 0)
    {

        return 0;
    }
    if (dp[idx][W] != -1)
    {
        return dp[idx][W];
    }

    if (W >= wt[idx])
    {

        return dp[idx][W] = max(val[idx] + solve(W - wt[idx], wt, val, n, idx + 1),
                                solve(W, wt, val, n, idx + 1));
    }
    else if (W < wt[idx])
    {
        return dp[idx][W] = solve(W, wt, val, n, idx + 1);
    }
}

//  tabulation top-down
int knapSack(int W, int wt[], int val[], int n)
{
  

    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= W; j++)
        {

            if (i == 0 or j == 0)
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= W; j++)
        {

            if (wt[i - 1] <= j)
            {

                dp[i][j] = max(dp[i - 1][j], val[i - 1] + dp[i - 1][j - wt[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {

        for (int j = 0; j <= W; j++)
        {
            cout << dp[i][j] << " ";
        }

        cout << "\n";
    }

    return dp[n][W];
}

int main()
{

    int n = 3, W = 4;
    // cin>>n>>W;

    int wt[n] = {4, 5, 1};
    int val[n] = {1, 2, 3};
 
    // cout << knapSack(W, wt, val, n) << "\n";

    memset(dp,-1,sizeof(dp));
    cout<<solve(W,wt,val,n,0)<<"\n";
}
