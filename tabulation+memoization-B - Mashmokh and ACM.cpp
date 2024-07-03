/*
 author:himanshu3198
 
*/
#include <bits/stdc++.h>

#define ll long long int
#define fr(i, n) for (int i = 0; i < (n); i++)
    #define rep(i, a, b) for (int i = (a); i < (b); i++)
        #define FORR(i, n) for (int i = (n); i >= 0; i--)
            #define fst first
#define snd second
#define E "\n"
#define pb push_back
#define mp make_pair
#define all(x)(x).begin(), (x).end()
#define mod 1000000007LL
#define MAX(a, b)((a) > (b) ? (a) : (b))
#define MIN(a, b)((a) < (b) ? (a) : (b))
#define ABS(x)((x) < 0 ? -(x) : (x))
#define setbits(x) __builtin_popcount(x)
#define vi vector < int >
    #define vl vector < long long int >
    #define vvi vector < vector < int >>
    #define vvl vector < vector < long long int >>
    #define INF 1e18
#define _Y puts("YES")
#define _N puts("NO")
#define showArr(v)\
for (auto it: v)\
    cout << it << " ";\
cout << E;
#define Print(ans) cout << ans << E;
#define sz(s) s.size();
#define Nitro()\
ios_base::sync_with_stdio(false);\
cin.tie(NULL);
using namespace std;

int gcd(int a, int b) {

    if (b == 0) return a;
    return (b, a % b);
}
int lcm(int a, int b) {

    return (a * b) / gcd(a, b);
}
bool comp(const vector < int > & a,
    const vector < int > & b) {
    if (a[0] == b[0]) {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}
int visited[100005];

ll ans;
ll dp[2002][2002];
unordered_map<int,vector<int>>multiples;
// ll memo(ll k,ll x,ll n) {
//     if (k==0) {
//         return 1;
//     }
//     if(dp[k][x]!=-1) return dp[k][x];
//     ll count=0;
//     for(auto &child:multiples[x]){
//         if(child>n) break;
//         count=(count+memo(k-1,child,n))%mod;
//     }
//     return dp[k][x]=count;
// }
void solve()
{
    ll n, k;
    cin >> n >> k;
    ans = 0LL;
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;j+=i){
            multiples[i].push_back(j);
        }
    }
    memset(dp,0,sizeof(dp));
    
    for(int i=1;i<=n;i++) dp[1][i]=1;
    
    for(int size=2;size<=k;size++){
        
        for(int i=1;i<=n;i++){
            
            ll count=0;
            for(auto &child:multiples[i]){
                count=(count+dp[size-1][child])%mod;
            }
            dp[size][i]=count;
    
        }
    }
  
    for(int i=1;i<=n;++i){
        
        // ans+=(memo(k-1,i,n));
        ans=(ans+dp[k][i]);
        ans=ans%mod;
    }
    cout << ans << E;

}

int main()
{
    Nitro();
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
