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
void solve(int tc)
{
    int i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
    string s;
    cin >> s;
    n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(26, 0));
    for (int i = 0; i < 26; ++i)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i - 1];
        int temp = (int)s[i - 1] - 97;
        dp[i][temp] += 1;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cnt = 0;
        if (l == r)
        {
            cout << 1 << ' ';
            continue;
        }
        for (int i = 0; i < 26; ++i)
        {
            if (dp[r][i] - dp[l - 1][i] >= 1)
            {
                cnt++;
            }
        }
        cout << cnt << ' ';
    }
    cout << endl;
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