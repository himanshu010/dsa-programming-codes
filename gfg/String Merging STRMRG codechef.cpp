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

string reduceString(string &s1)
{
    int n = s1.size();
    string a;
    a += a[0];
    for (int i = 1; i < n; ++i)
    {
        if (s1[i] != s1[i - 1])
        {
            a += s1[i];
        }
    }
    return a;
}

void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    cin >> n >> m;
    string s1, s2;
    cin >> s1 >> s2;
    string a, b;
    //   if (n != 1) {
    a = reduceString(s1);
    //   }
    //   if (m != 1) {
    b = reduceString(s2);
    //   }

    //   if (n == 1) {
    //     a = s1;
    //   }
    //   if (m == 1) {
    //     b = s2;
    //   }

    n = a.size();
    m = b.size();

    vvi dp(n + 1, vi(m + 1));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << n + m - dp[n][m] << endl;
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
    int t;
    cin >> t;
    while (t--)
    {
        solve(tc);
        tc++;
    }
}