/*
*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.codes )               |
|                                                           |
|                                                           |
*-----------------------------------------------------------*
*/
#include<bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int,int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define PQ priority_queue
using namespace std;


void preCompute() {

}
void solve(int tc) {
    int i, j, k, n, m, ans = INT_MAX, cnt = 0, sum = 0;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    vvi dp(n, vi(m));
    for (int i = 0; i < m; ++i)
    {
        dp[0][i] = a[0][i];
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int mn = INT_MAX;
            for (int k = 0; k < m; ++k)
            {
                if (k != j) {
                    mn = min(mn, dp[i - 1][k]);
                }
            }
            dp[i][j] = mn + a[i][j];
        }
    }

    for (auto x : dp[n - 1]) {
        ans = min(ans, x);
    }
    cout << ans << endl;
}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    preCompute();
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}