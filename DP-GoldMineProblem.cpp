#include <bits/stdc++.h>
#define E endl
#define Max 100
using namespace std;

 int GoldMine(int arr[][100],int n,int m)
{

    int dp[n][m];

    for (int j = m - 2; j >= 0; j--)
    {

        for (int i = 0; i < n; i++)
        {

            if (j == m - 2)
            {

                if (i == 0)
                {
                    dp[i][j] = max(arr[i][j] + arr[i][j + 1], arr[i][j] + arr[i + 1][j + 1]);
                }
                else if (i == n - 1)
                {
                    dp[i][j] = max(arr[i][j] + arr[i][j + 1], arr[i][j] + arr[i - 1][j + 1]);
                }

                else
                {
                    dp[i][j] = max(max(arr[i][j] + arr[i][j + 1], arr[i][j] + arr[i - 1][j + 1]), arr[i][j] + arr[i + 1][j + 1]);
                }
            }

            else
            {

                if (i == 0)
                {
                    dp[i][j] = max(arr[i][j] + dp[i][j + 1], arr[i][j] + dp[i + 1][j + 1]);
                }
                else if (i == n - 1)
                {
                    dp[i][j] = max(arr[i][j] + dp[i][j + 1], arr[i][j] + dp[i - 1][j + 1]);
                }

                else
                {
                    dp[i][j] = max(max(arr[i][j] + dp[i][j + 1], arr[i][j] + dp[i - 1][j + 1]), arr[i][j] + dp[i + 1][j + 1]);
                }
            }
        }
    }
    int maxElement=dp[0][0];

     for(int i=1;i<3;i++)

     {
         if(dp[i][0]>maxElement)
         maxElement=dp[i][0];
            
         
     }
   
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         // cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    return maxElement;



}

int main()
{
    int n,m;
    cin>>n>>m;
    int mat[Max][Max];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
        }
    }

    cout<<GoldMine(mat,n,m)<<"\n";
}