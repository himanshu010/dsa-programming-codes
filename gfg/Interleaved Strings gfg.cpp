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
using namespace std;

bool check(string a, string b, string c)
{
    // cout << a << ' ' << b << endl;
    if (a.size() != b.size() + c.size())
    {
        return false;
    }

    int n = a.size();
    int m = b.size();
    vector<pair<char, bool>> aa(n);
    for (int i = 0; i < n; ++i)
    {
        aa[i] = {a[i], 1};
    }

    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= n; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i <= m; ++i)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (b[i - 1] == a[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    for (int i = 1; i <= m; ++i)
    {
        int mx = 0;
        int index = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (dp[i][j] > mx)
            {
                mx = dp[i][j];
                index = j;
            }
        }
        aa[index - 1].S = 0;
    }

    if (dp[m][n] != b.size())
    {
        return 0;
    }
    int i = 0, j = 0, o = c.size();
    while (i < n and j < o)
    {
        if (aa[i].S == 0)
        {
            i++;
            continue;
        }

        if (aa[i].F != c[j])
        {
            return false;
        }
        else
        {
            i++;
            j++;
        }
    }

    return true;
}

void solve(int tc)
{
    int i, j, k, n, m, cnt = 0, sum = 0;
    string a, b, c;
    cin >> a >> b >> c;
    bool ans = check(a, b, c) || check(a, c, b);
    cout << ans << endl;
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
    int tc = 1;
    // int t;cin>>t;while(t--)
    {
        solve(tc);
        tc++;
    }
}