#include <bits/stdc++.h>
using namespace std;

int min_cost(vector<int> &cost)
{

    int n = cost.size();

    vector<int> dp(n);

    if (n == 1)
        return cost[0];
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++)
    {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    for (int i = 0; i < dp.size(); i++)
    {
        cout << dp[i] << " ";
    }
    cout<<"\n";
    return min(dp[n-2],dp[n-1]);
}
int main()
{
    vector<int >cost  ={1,100,1,1,1,100,1,1,100,1};
    // vector<int> cost = {10, 15, 20};
    cout << min_cost(cost);
    return 0;
}