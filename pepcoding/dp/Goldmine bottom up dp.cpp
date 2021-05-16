/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|            ( website: himanshuaswal.com )                 |
*-----------------------------------------------------------*
*/
#include <bits/stdc++.h>
#define moduli 998244353
#define int long long int
#define ld long double
#define F first
#define S second
#define P pair<int, int>
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vb vector<bool>
#define um unordered_map
#define PQ priority_queue
using namespace std;

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    vvi a(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }
    vvi dp(n, vi(m, -1));

    for (int i = 0; i < n; ++i)
    {
        dp[i][m - 1] = a[i][m - 1];
    }
    for (int j = m - 2; j >= 0; --j)
    {
        for (int i = 0; i < n; ++i)
        {
            int aa = 0, b = 0, c = 0;
            if (i > 0)
            {
                aa = dp[i - 1][j + 1];
            }
            if (i < n - 1)
            {
                b = dp[i + 1][j + 1];
            }
            c = dp[i][j + 1];
            dp[i][j] = a[i][j] + max(aa, max(b, c));
        }
    }

    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp[i][0]);
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}