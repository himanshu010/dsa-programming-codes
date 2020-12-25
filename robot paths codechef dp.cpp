/*

*-----------------------------------------------------------*
|                                                           |
|                                                           |
|               AUTHOR: Himanshu Aswal                      |
|     ( website: himanshu010.github.io/Portfolio_website )  |
|                                                           |
|                                                           |
*-----------------------------------------------------------*

*/

#include <bits/stdc++.h>
#define moduli 1000000007
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
#define R return

using namespace std;

int dp[1001][1001];

int numWays(int n, int m)
{
    // Base case
    if (dp[0][0] == -1)
    {
        return 0;
    }

    // first column
    for (int i = 0; i < m; ++i)
    {
        if (dp[0][i] == -1)
        {
            break;
        }
        dp[0][i] = 1;
    }

    // first row
    for (int i = 0; i < n; ++i)
    {
        if (dp[i][0] == -1)
        {
            break;
        }
        dp[i][0] = 1;
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            // if cell is blocked then leave it
            if (dp[i][j] == -1)
            {
                continue;
            }

            dp[i][j] = 0;

            // cout << i << " " << j << endl;

            if (dp[i][j - 1] != -1)
            {
                // cout << "+++" << endl;
                dp[i][j] = dp[i][j - 1] % moduli;
            }
            if (dp[i - 1][j] != -1)
            {
                // cout << "---" << endl;
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % moduli;
            }
        }
    }
    if (dp[n - 1][m - 1] == -1)
    {
        return 0;
    }

    // for (int i = 0; i < n; ++i)
    // {
    //   for (int j = 0; j < m; ++j)
    //   {
    //     cout << dp[i][j] << " ";
    //   }
    //   cout << endl;
    // }
    return dp[n - 1][m - 1];
}

void solve()
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    memset(dp, 0, sizeof dp);

    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i)
    {
        int x, y;
        cin >> x >> y;
        dp[x - 1][y - 1] = -1;
    }

    cout << numWays(n, m) << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;while(t--)
    {
        solve();
    }
}