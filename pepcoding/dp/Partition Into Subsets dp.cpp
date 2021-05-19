/*
*-----------------------------------------------------------*
|               AUTHOR: Himanshu Aswal                      |
|             ( website: himanshuaswal.com )                |
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

void preCompute()
{
}
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> k;
    vvi dp(n + 1, vi(k + 1));
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= k; ++j)
        {
            if (i == 0 or j == 0)
            {
                dp[i][j] = 0;
                continue;
            }

            if (i == j)
            {
                dp[i][j] = 1;
                continue;
            }

            dp[i][j] = (dp[i - 1][j] * j) + dp[i - 1][j - 1];
        }
    }

    cout << dp[n][k] << endl;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
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