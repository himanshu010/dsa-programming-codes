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

void solve(int tc) {
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    cin >> m;
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i)
    {
        int mx = INT_MIN;
        for (int j = 0; j < n; ++j)
        {
            if (i == 0 or j == 0) {
                dp[i][j] = 0;
                continue;
            }
            mx = max(mx, dp[i - 1][j - 1] - a[j - 1]);

            dp[i][j] = max(dp[i][j - 1], a[j] + mx);
        }
    }

    cout << dp[m][n - 1] << endl;



}
int32_t main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}