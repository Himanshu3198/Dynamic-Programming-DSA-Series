#include <bits/stdc++.h>
#define ll long  long int
 // #define PRINT_OUTPUT()
using namespace std;


vector < int > getInput(int n) {
    vector < int > v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    return v;
}


bool comp(const vector < int > & a,
    const vector < int > & b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
// long long int dp[100001][3];

// long long int memo(vector < int > & h1, vector < int > & h2, int flag, int idx) {

//     if (idx == h1.size()) return 0;
//     if (dp[idx][flag] != -1) return dp[idx][flag];

//     if (flag == 0) {

//         long long int op1 = h1[idx] + memo(h1, h2, 1, idx + 1);
//         long long int op2 = h2[idx] + memo(h1, h2, 2, idx + 1);
//         dp[idx][flag] = max(op1, op2);
//     } else if (flag == 1) {
//         dp[idx][flag] = h2[idx] + memo(h1, h2, 2, idx + 1);
//     } else {
//         dp[idx][flag] = h1[idx] + memo(h1, h2, 1, idx + 1);
//     }
//     dp[idx][flag] = max(dp[idx][flag], memo(h1, h2, flag, idx + 1));
//     return dp[idx][flag];
// }

int n, t = 1;
vector < int > a;
int main() {
    //   cin >> t;
    while (t--) {
        //   int n;
        cin >> n;

        vector < int > h1, h2;
        long long int dp[100001][3];
        memset(dp, -1LL, sizeof(dp));
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            h1.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            h2.push_back(x);
        }
        //   cout<<memo(h1,h2,0,0)<<"\n";
     
        dp[0][0] = 0;
        dp[0][1] = h1[0];
        dp[0][2] = h2[0];
        for (int i = 1; i <= h1.size(); i++) {
            for (int flag = 0; flag < 3; flag++) {

                if (flag == 0) {
                    ll op1 = h1[i] + dp[i - 1][2];
                    ll op2 = h2[i] + dp[i - 1][1];
                    dp[i][flag] = max(op1, op2);
                }
                else if (flag == 1) {
                    dp[i][flag] = h1[i] + dp[i - 1][2];
                } else {
                    dp[i][flag] = h2[i] + dp[i - 1][1];
                }
                dp[i][flag]=max(dp[i][flag],dp[i-1][flag]);
            }


        }
        //   for (int i = 0; i <= h1.size(); i++) {

        //     for (int j = 0; j < 3; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << "\n";

        // }
        
        cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<"\n";

    }


    return 0;
}
