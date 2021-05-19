
#include <bits/stdc++.h>
using namespace std;
#define N 500005
int n;
long long a[N], b[N], f[N], ans=0, t=0;
int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%lld", &a[i]);
	for (int i = 1; i <= n; i++) scanf ("%lld", &b[i]), t += a[i]*b[i];
	ans = t;
	for (int i = 2; i <= n; i++)
    { for (int j = 1; j <= i - 1; j++)

      {
		f[i+j] += (a[i] - a[j]) * b[j] + (a[j] - a[i]) * b[i];

        
		ans = max (ans, t + f[i+j]);

      }

    }


    // for(int i=1;i<=n;i++){

    //    cout<<f[i]<<" ";
    // }
	printf ("%lld\n", ans);
	return 0;
}